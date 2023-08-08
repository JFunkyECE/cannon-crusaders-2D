#ifndef menus_hpp
#define menus_hpp
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>
#include <string>


namespace menu{

    struct Character {
        GLuint textureID;  // Texture ID
        int width, height; // Glyph size
        int bearingX, bearingY;  // Offset from baseline to left/top of glyph
        unsigned int advance;  // Horizontal offset to advance to next glyph
    };

class Menu{
//purpose of this class is to contain graphic rendering for
//start menu, pause menu, and end screen 

    Menu(){

        glGenVertexArrays(1, &VAO_);
        glBindVertexArray(VAO_);
        glGenBuffers(1, &VBO_);
        glBindBuffer(GL_ARRAY_BUFFER, VBO_);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        
        if (FT_Init_FreeType(&ft_)) {
        // Handle error
        }
        FT_Face face;
        if (FT_New_Face(ft_, "./font/arial_bold.ttf", 0, &face)) {
        // Handle errors
        }
        FT_Set_Pixel_Sizes(face, 0, 32); //sets font size
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        for (unsigned char c = 0; c < 128; c++) {
        // Load character glyph 
            if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
                // Handle error
                continue;
            }
            GLuint texture;
            glGenTextures(1, &texture);
            glBindTexture(GL_TEXTURE_2D, texture);
            glTexImage2D(
                GL_TEXTURE_2D, 
                0, 
                GL_RED, 
                face->glyph->bitmap.width, 
                face->glyph->bitmap.rows, 
                0, 
                GL_RED, 
                GL_UNSIGNED_BYTE, 
                face->glyph->bitmap.buffer
        );
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        Character character = {
            texture,
            face->glyph->bitmap.width, face->glyph->bitmap.rows,
            face->glyph->bitmap_left, face->glyph->bitmap_top,
            static_cast<unsigned int>(face->glyph->advance.x)
        };
        characters_.insert(std::pair<char, Character>(c, character));
        }
        glBindTexture(GL_TEXTURE_2D, 0);
        FT_Done_Face(face);
        FT_Done_FreeType(ft_);
    }


    ~Menu(){
        glDeleteVertexArrays(1, &VAO_);
        glDeleteBuffers(1, &VBO_);
        for (auto &pair : characters_) {
            glDeleteTextures(1, &pair.second.textureID);
        }
    }

//start menu
    void renderStartMenu();
//contains the following text
//      Cannon Crusaders
//
//      Start: Press ENTER
//      Quit: Press Q
//      How to Play
//      -> move right
//      <- move left
//      SPACE shoot


//ingame
    void renderInGame();
//enemies left counter thats it

//Pause menu
    void renderPause();
//Small square goes over screen with following text
//Paused
//Press ENTER to continue
//Press R to Restart
//Press M to go back to the menu
//Press Q to quit application


//ENDGAME
    void renderEndGame();
//depending on win or lose
//Great Job or Almost there
//press R to restart
//press M to go back to menu
//press Q to quit application

//render text function 
    void renderText(const std::string& text, float x, float y);

private:
GLuint VAO_, VBO_;
FT_Library ft_;
std::map<char, Character> characters_;
};

}
#endif
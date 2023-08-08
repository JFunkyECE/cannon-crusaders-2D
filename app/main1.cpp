#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <ft2build.h>
#include <iostream>
#include <map>

#include FT_FREETYPE_H

std::map<GLchar, GLuint> CharacterTextures;

void loadFontCharacters(FT_Face face) {
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);  
    for (GLubyte c = 0; c < 128; c++) {
        if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
            std::cerr << "Failed to load Glyph" << std::endl;
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
        
        CharacterTextures[c] = texture;
    }
    glBindTexture(GL_TEXTURE_2D, 0);
}

void renderText(const std::string& text, float x, float y, float scale) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(scale, scale, scale);
    
    for (char c : text) {
        if (CharacterTextures.find(c) != CharacterTextures.end()) {
            glBindTexture(GL_TEXTURE_2D, CharacterTextures[c]);
            glBegin(GL_QUADS);
                glTexCoord2f(0, 0); glVertex2f(0, 0);
                glTexCoord2f(1, 0); glVertex2f(1, 0);
                glTexCoord2f(1, 1); glVertex2f(1, -1);
                glTexCoord2f(0, 1); glVertex2f(0, -1);
            glEnd();
            glTranslatef(1.0f, 0, 0); // Move cursor for next character
        }
    }

    glBindTexture(GL_TEXTURE_2D, 0);
    glPopMatrix();
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "Jacob", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    // FreeType
    FT_Library ft;
    if (FT_Init_FreeType(&ft)) {
        std::cerr << "Failed to initialize FreeType" << std::endl;
        return -1;
    }

    FT_Face face;
    if (FT_New_Face(ft, "./font/arial_bold.ttf", 0, &face)) {
        std::cerr << "Failed to load font" << std::endl;
        return -1;
    }

    FT_Set_Pixel_Sizes(face, 0, 48);

    loadFontCharacters(face);
    FT_Done_Face(face);
    FT_Done_FreeType(ft);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        renderText("Jacob is Cool", 350, 300, 1.0f);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

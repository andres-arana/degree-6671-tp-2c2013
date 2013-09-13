#include "app/graphics/grid.h"

app::graphics::Grid::Grid(int size) :
  vertexBuffer(12 * (2 * size + 1)),
  indexBuffer(4 * (2 * size + 1)) {
    // Compute vertex positions and fill vertex buffer
    for (int i = 0; i < size; i++) {
      int offset = 24 * i;

      offset = assignVertex(offset, -size, i+1, 0);
      offset = assignVertex(offset, size, i+1, 0);
      offset = assignVertex(offset, -size, -(i+1), 0);
      offset = assignVertex(offset, size, -(i+1), 0);
      offset = assignVertex(offset, i+1, -size, 0);
      offset = assignVertex(offset, i+1, size, 0);
      offset = assignVertex(offset, -(i+1), -size, 0);
      offset = assignVertex(offset, -(i+1), size, 0);
    }
    int offset = 24 * size;
    offset = assignVertex(offset, -size, 0, 0);
    offset = assignVertex(offset, size, 0, 0);
    offset = assignVertex(offset, 0, -size, 0);
    offset = assignVertex(offset, 0, size, 0);

    // The vertices are in order already
    for (unsigned int i = 0; i < indexBuffer.size(); i++) {
      indexBuffer[i] = i;
    }
  }

void app::graphics::Grid::render(
    const glm::mat4 &modelMatrix, 
    const sys::shaders::ShaderProgram &program) {

  glm::mat3 normalMatrix = glm::mat3(1.0f);

  sys::shaders::ShaderParam normalMatrixParam = program.getUniformParam("NormalMatrix");
  if (normalMatrixParam.isAvailable()) {
    glUniformMatrix3fv( normalMatrixParam.getHandle(), 1, GL_FALSE, &normalMatrix[0][0]);
  }

  sys::shaders::ShaderParam modelMatrixParam = program.getUniformParam("ModelMatrix");
  if (modelMatrixParam.isAvailable()) {
    glUniformMatrix4fv( modelMatrixParam.getHandle(), 1, GL_FALSE, &modelMatrix[0][0]); 
  }

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, &vertexBuffer[0]);
  glDrawElements(GL_LINES, indexBuffer.size(), GL_UNSIGNED_INT, &indexBuffer[0]);
  glDisableClientState(GL_VERTEX_ARRAY);
}


unsigned int app::graphics::Grid::assignVertex(unsigned int offset, GLfloat x, GLfloat y, GLfloat z) {
  vertexBuffer[offset++] = x;
  vertexBuffer[offset++] = y;
  vertexBuffer[offset++] = z;
  return offset;
}


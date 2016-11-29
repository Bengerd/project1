#include "screenwidget.h"
#include <QOpenGLShaderProgram>
#include "vertex.h"

// Create a colored triangle
static const Vertex sg_vertexes[] = {
  Vertex( QVector3D( 0.00f,  0.75f, 1.0f), QVector3D(1.0f, 0.0f, 0.0f) ),
  Vertex( QVector3D( 0.75f, -0.75f, 1.0f), QVector3D(0.0f, 1.0f, 0.0f) ),
  Vertex( QVector3D(-0.75f, -0.75f, 1.0f), QVector3D(0.0f, 0.0f, 1.0f) )
};

void ScreenWidget::initializeGL()
{
    // Set up the rendering context, load shaders and other resources, etc.:
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    {
      // Create Shader (Do not release until VAO is created)
      m_program = new QOpenGLShaderProgram();
      m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/simple.vert");
      m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/simple.frag");
      m_program->link();
      m_program->bind();

      // Create Buffer (Do not release until VAO is created)
      m_vertex.create();
      m_vertex.bind();
      m_vertex.setUsagePattern(QOpenGLBuffer::StaticDraw);
      m_vertex.allocate(sg_vertexes, sizeof(sg_vertexes));

      // Create Vertex Array Object
      m_object.create();
      m_object.bind();
      m_program->enableAttributeArray(0);
      m_program->enableAttributeArray(1);
      m_program->setAttributeBuffer(0, GL_FLOAT, Vertex::positionOffset(), Vertex::PositionTupleSize, Vertex::stride());
      m_program->setAttributeBuffer(1, GL_FLOAT, Vertex::colorOffset(), Vertex::ColorTupleSize, Vertex::stride());

      // Release (unbind) all
      m_object.release();
      m_vertex.release();
      m_program->release();
    }

}

void ScreenWidget::resizeGL(int w, int h)
{
    // Update projection matrix and other size related settings:
    //m_projection.setToIdentity();
    //m_projection.perspective(45.0f, w / float(h), 0.01f, 100.0f);

}

void ScreenWidget::paintGL()
{
    // Draw the scene:
    glClear(GL_COLOR_BUFFER_BIT);
    m_program->bind();
     {
       m_object.bind();
       glDrawArrays(GL_TRIANGLES, 0, sizeof(sg_vertexes) / sizeof(sg_vertexes[0]));
       m_object.release();
     }
     m_program->release();
}

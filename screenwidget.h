#ifndef SCREENWIDGET_H
#define SCREENWIDGET_H
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

class QOpenGLShaderProgram;

class ScreenWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    ScreenWidget(QWidget *parent) : QOpenGLWidget(parent) { }

protected:
    void initializeGL();

    void resizeGL(int w, int h);

    void paintGL();

private:
  // OpenGL State Information
  QOpenGLBuffer m_vertex;
  QOpenGLVertexArrayObject m_object;
  QOpenGLShaderProgram *m_program;
};

#endif // SCREENWIDGET_H

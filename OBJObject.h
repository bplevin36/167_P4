#ifndef OBJOBJECT_H
#define OBJOBJECT_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <cmath>
#include "Geode.h"

class OBJObject : public Geode
{
protected:
	std::vector<unsigned int> indices;
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> normals;

private:
glm::vec3 position;
glm::mat4 toWorld;
glm::mat4 rotate;
glm::mat4 translation;
glm::mat4 scaling;
glm::mat4 orbiting;

float angle, orbitAngle = 0.0f;
float scaleFactor = 1.0f;
glm::vec3 max = glm::vec3(-INFINITY);
glm::vec3 min = glm::vec3(INFINITY);

public:
	void setupBuffers();
	OBJObject(const char* filepath);
	OBJObject();

	static GLuint shaderProgram;
	void translate(glm::vec3);
	void scale(float);
	void orbit(float, glm::vec3);
	void reset();
	void parse(const char* filepath);
	//to satisfy inheritance of Geode
	virtual void update(glm::mat4 C);
	virtual void draw(GLuint);

	void update();
	void spin(float deg);
	static void print_matrix(glm::mat4);
	std::vector<glm::vec3> getVertices();
	glm::vec3 getNormal(int);
	glm::mat4 getToWorld();

	GLuint VBO, VAO, VBON, EBO;
};

#endif
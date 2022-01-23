#include <iostream>
#include <sstream>
#include <random>

#include <GLFW/glfw3.h>

void error_callback(int error, const char* description) {
	fprintf(stderr, "Error: %s\n", description);
}

void draw(double x, double y, bool color) {
	if (color) {
		glColor3f(1.0f, 1.0f, 1.0f); // white
	}
	else {
		glColor3f(1.0f, 0.0f, 0.0f); // red
	}

	glVertex2f(x, y);
}

double montecarlo(long int points) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_real_distribution<double> dist(-1.0, 1.0);

	int count_in = 0;
	int count_out = 0;

	while (points > 0) {

		double rx = dist(rng);
		double ry = dist(rng);

		if (pow(rx, 2) + pow(ry, 2) <= 1) {
			count_in++;
			draw(rx, ry, true);
		}
		else {
			count_out++;
			draw(rx, ry, false);
		}

		points--;
	}

	return (double)count_in / (double)(count_out + count_in) * 4;
}

int main()
{
	long int points;
	std::cout << "Insert the number of points you want to generate:" << std::endl;
	std::cin >> points;

	glfwInit();
	glfwSetErrorCallback(error_callback);

	std::ostringstream stream;
	stream << "Monte Carlo method with " << points << " points";
	GLFWwindow* window = glfwCreateWindow(1000, 1000, stream.str().c_str(), NULL, NULL);
	glfwMakeContextCurrent(window);

	glPointSize(1.5f);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);

	std::cout << "Approximated pi value: " << montecarlo(points);

	glEnd();
	glfwSwapBuffers(window);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}

	glfwTerminate();
}

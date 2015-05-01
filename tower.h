static float tower[28][3] = 
{
	// front
  	{  0.7f, 0.6f,  0.0f }, // top right
  	{ -0.7f, 0.6f,  0.0f }, // top left
  	{ -0.7f, 0.3f,  0.0f }, // bot left
  	{  0.7f, 0.3f,  0.0f }, // bot right
  	// cd drive
  	{  0.0f, 0.5f,  0.01f }, // top right
  	{ -0.6f, 0.5f,  0.01f }, // top left
  	{ -0.6f, 0.4f,  0.01f }, // bot left
  	{  0.0f, 0.4f,  0.01f }, // bot right
	// back   
  	{  0.7f, 0.6f, -1.0f }, // top right
  	{ -0.7f, 0.6f, -1.0f }, // top left
  	{ -0.7f, 0.3f, -1.0f }, // bot left
  	{  0.7f, 0.3f, -1.0f }, // bot right 
  	// top
  	{  0.7f,  0.6f, -1.0f }, // top right
  	{ -0.7f,  0.6f, -1.0f }, // top left
  	{ -0.7f,  0.6f,  0.0f }, // bot left
  	{  0.7f,  0.6f,  0.0f }, // bot right
  	// bot
  	{  0.7f,  0.3f, -1.0f }, // top right
  	{ -0.7f,  0.3f, -1.0f }, // top left
  	{ -0.7f,  0.3f,  0.0f }, // bot left
  	{  0.7f,  0.3f,  0.0f }, // bot right
  	// right
  	{ 0.7f,  0.6f, -1.0f }, // top right
  	{ 0.7f,  0.6f,  0.0f }, // top left
  	{ 0.7f,  0.3f,  0.0f }, // top left
  	{ 0.7f,  0.3f, -1.0f }, // bot right
  	// left
  	{ -0.7f, 0.6f,  0.0f }, // top right
  	{ -0.7f, 0.6f, -1.0f }, // top left
  	{ -0.7f, 0.3f, -1.0f }, // bot left
  	{ -0.7f, 0.3f,  0.0f } // bot right
};

/*
A aplicar no ficheiro computer.cpp
Desenha as leds e o botao de power
Provavelmente com texturas nao e necessaria?

void drawCircle (float x, float y, float z, float radius)
{
	float i;
	glColor3f( 0.0, 0.0, 0.0 );
	glBegin(GL_LINES);
		for(i = 0; i < 2*M_PI; i+=0.02) {
			glVertex3f(x, y, z);
			glVertex3f(x + radius * cos(i), y + radius * sin(i), z);
  		}
  	glEnd();
}*/

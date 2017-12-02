// Este código está baseado nos exemplos disponíveis no livro
// "OpenGL SuperBible", 2nd Edition, de Richard S. e Wright Jr.

#include <GL/glut.h>
#include <unistd.h>
#include "modelo.hpp"     // needed to sleep

GLfloat angle, fAspect;

float raio_juntas = 2.0f;

//Juntas
Modelo cintura(raio_juntas);
Modelo virilha_d(raio_juntas);
Modelo virilha_e(raio_juntas);
Modelo joelho_d(raio_juntas);
Modelo joelho_e(raio_juntas);
Modelo tornozelo_d(raio_juntas);
Modelo tornozelo_e(raio_juntas);
Modelo ponta_pe_d(raio_juntas);
Modelo ponta_pe_e(raio_juntas);
Modelo espinha_d_1(raio_juntas);
Modelo espinha_d_2(raio_juntas);
Modelo espinha_d_3(raio_juntas);
Modelo ombro_d(raio_juntas);
Modelo ombro_e(raio_juntas);
Modelo cotovelo_d(raio_juntas);
Modelo cotovelo_e(raio_juntas);
Modelo pulso_d(raio_juntas);
Modelo pulso_e(raio_juntas);
Modelo junta_pescoco(raio_juntas);

//Partes do corpo - baixo
Modelo quadril(8.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo perna_d(20.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo perna_e(20.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo canela_d(20.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo canela_e(20.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo pe_d(4.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo pe_e(4.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo dedos_d(4.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo dedos_e(4.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);

//Partes do corpo - cima
Modelo tronco_1(6.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo tronco_2(14.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo tronco_3(6.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);

Modelo pescoco(6.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo cabeca(6.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);

Modelo saboneteira_d(8.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo saboneteira_e(8.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);

Modelo braco_e(16.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo braco_d(16.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);

Modelo antebraco_e(16.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo antebraco_d(16.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);

Modelo mao_e(4.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo mao_d(4.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f);

void desenha_junta(){
	glPushMatrix();
		glScalef(raio_juntas, raio_juntas, raio_juntas);
		glutSolidSphere(1.0f, 20, 20);
	glPopMatrix();
}

void desenha_parte_cima(){
	//desenha tronco
	glColor3f(1.0f, 0.5f, 1.0f);
	glTranslatef(tronco_1.get_deslocamento_x(), tronco_1.get_deslocamento_y(), tronco_1.get_deslocamento_z());
	glPushMatrix();
		glScalef(tronco_1.get_largura(), tronco_1.get_altura(), tronco_1.get_profundidade());
		glutSolidCube(1.0f);
	glPopMatrix();

}

void desenha_parte_baixo(){
	//desenha o quadril
	glColor3f(1.0f, 0.5f, 1.0f);
	glTranslatef(quadril.get_deslocamento_x(), quadril.get_deslocamento_y(), quadril.get_deslocamento_z());
	glPushMatrix();
		glScalef(quadril.get_largura(), quadril.get_altura(), quadril.get_profundidade());
		glutSolidCube(1.0f);
	glPopMatrix();

	//desenha a virilha_d
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(cintura.get_deslocamento_x(), cintura.get_deslocamento_y(), cintura.get_deslocamento_z());
	desenha_junta();

		//desenha a virilha_e
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(cintura.get_deslocamento_x(), cintura.get_deslocamento_y(), cintura.get_deslocamento_z());
	desenha_junta();
}


void DesenhaEixos(void)
{
	glBegin(GL_LINES);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(10.0f,0.0f,0.0f);
		glColor3f(0.0f,1.0f,0.0f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,10.0f,0.0f);
		glColor3f(0.0f,0.0f,1.0f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,10.0f);
	glEnd();
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{

	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	// Especifica posição do observador e do alvo
    gluLookAt(0,80,200, 0,0,0, 0,1,0);
	// Limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	// //desenha base
	// glColor3f(0.0f, 0.3f, 1.0f);
	// glPushMatrix();
	// 	glScalef(base_l, base_a, base_p);
	// 	glutSolidCube(1.0f);
	// glPopMatrix();
    //
	// //desenha a 1ª junta
	// glColor3f(0.7f, 0.7f, 0.7f);
	// glTranslatef(0.0f, (base_a / 2) + (junta_r / 2), 0.0f);
	// glRotatef(r_junta1_x, 1.0, 0.0f, 0.0);
	// glRotatef(r_junta1_y, 0.0, 1.0f, 0.0f);
	// glRotatef(r_junta1_z, 0.0, 0.0f, 1.0f);
	// glPushMatrix();
	// 	glScalef(junta_r, junta_r, junta_r);
	// 	glutSolidSphere(1.0f, 10, 10);
	// glPopMatrix();

	//desenha a cintura
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(cintura.get_deslocamento_x(), cintura.get_deslocamento_y(), cintura.get_deslocamento_z());
	desenha_junta();

	glPushMatrix();
		desenha_parte_baixo();
	glPopMatrix();

	glPushMatrix();
		desenha_parte_baixo();
	glPopMatrix();

	glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};		 // "cor"
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho"
	GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
	GLint especMaterial = 60;

 	// Especifica que a cor de fundo da janela será preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a refletância do material
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);
	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_NORMALIZE);

    angle=45;
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de projeção
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de projeção
	glLoadIdentity();

	// Especifica a projeção perspectiva
    gluPerspective(angle,fAspect,0.4,500);
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divisão por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
    glViewport(0, 0, w, h);

	// Calcula a correção de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10) angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130) angle += 5;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}

void keyBoardfunc(unsigned char key, int x, int y){

	// usleep(100);
    //
	// //Roda Base
	// if(key == 122){
	// 	rotation_base += 3;
	// 	if(rotation_base > 360.0f){
	// 		rotation_base = 0.0f;
	// 	}
	// }else
	// if(key == 120){
	// 	rotation_base -= 3;
	// 	if(rotation_base < 0.0f){
	// 		rotation_base = 360.0f;
	// 	}
	// }
    //
    //
	// //Roda 1ª junta
	// if(key == 97){
	// 	r_junta1_y += 3;
	// 	if(r_junta1_y > 180.0f){
	// 		r_junta1_y = 180.0f;
	// 	}
	// }else
	// if(key == 100){
	// 	r_junta1_y -= 3;
	// 	if(r_junta1_y < 0.0f){
	// 		r_junta1_y = 0.0f;
	// 	}
	// }else
	// if(key == 119){
	// 	r_junta1_z += 3;
	// 	if(r_junta1_z > 45.0f){
	// 		r_junta1_z = 45.0f;
	// 	}
	// }else
	// if(key == 115){
	// 	r_junta1_z -= 3;
	// 	if(r_junta1_z < 0.0f){
	// 		r_junta1_z = 0.0f;
	// 	}
	// }
    //
    //
	// //Roda 2ª junta
	// if(key == 102){
	// 	r_junta2_y += 3;
	// 	if(r_junta2_y > 180.0f){
	// 		r_junta2_y = 180.0f;
	// 	}
	// }else
	// if(key == 104){
	// 	r_junta2_y -= 3;
	// 	if(r_junta2_y < 0.0f){
	// 		r_junta2_y = 0.0f;
	// 	}
	// }else
	// if(key == 116){
	// 	r_junta2_z += 3;
	// 	if(r_junta2_z > 45.0f){
	// 		r_junta2_z = 45.0f;
	// 	}
	// }else
	// if(key == 103){
	// 	r_junta2_z -= 3;
	// 	if(r_junta2_z < 0.0f){
	// 		r_junta2_z = 0.0f;
	// 	}
	// }
    //
	// //Roda 3ª junta
	// if(key == 113){
	// 	r_junta3_y += 3;
	// 	if(r_junta3_y > 180.0f){
	// 		r_junta3_y = 180.0f;
	// 	}
	// }else
	// if(key == 101){
	// 	r_junta3_y -= 3;
	// 	if(r_junta3_y < 0.0f){
	// 		r_junta3_y = 0.0f;
	// 	}
	// }
    //
	// //Abre e fecha mãos
	// if(key == 114){
	// 	abertura_dedo += 1;
	// 	if(abertura_dedo > 3.0f){
	// 		abertura_dedo = 3.0f;
	// 	}
	// }else
	// if(key == 121){
	// 	abertura_dedo -= 1;
	// 	if(abertura_dedo < 0.0f){
	// 		abertura_dedo = 0.0f;
	// 	}
	// }
    //
    //
    //
	// glutPostRedisplay();
}

// Programa Principal
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640,480);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	glutKeyboardFunc(&keyBoardfunc);
	Inicializa();
	glutMainLoop();
}

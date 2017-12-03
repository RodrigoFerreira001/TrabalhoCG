// Este código está baseado nos exemplos disponíveis no livro
// "OpenGL SuperBible", 2nd Edition, de Richard S. e Wright Jr.

#include <GL/glut.h>
#include <unistd.h>
#include "modelo.hpp"     // needed to sleep

GLfloat angle, fAspect;

float raio_juntas = 2.0f;
int joelho_sentido = 0;

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
Modelo quadril(10.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo perna_d(20.0f, 5.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo perna_e(20.0f, 5.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo canela_d(20.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo canela_e(20.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo pe_d(4.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo pe_e(4.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo dedos_d(4.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo dedos_e(4.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

//Partes do corpo - cima
Modelo tronco_1(6.0f, 10.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo tronco_2(14.0f, 12.0f, 12.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo tronco_3(6.0f, 14.0f, 14.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

Modelo pescoco(6.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo cabeca(10.0f, 10.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

Modelo saboneteira_d(8.0f, 4.0f, 14.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo saboneteira_e(8.0f, 4.0f, 14.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

Modelo braco_e(16.0f, 5.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo braco_d(16.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

Modelo antebraco_e(16.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo antebraco_d(16.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

Modelo mao_e(4.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo mao_d(4.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

void desenha_junta(){
	glPushMatrix();
		glScalef(raio_juntas, raio_juntas, raio_juntas);
		glutSolidSphere(1.0f, 20, 20);
	glPopMatrix();
}

void desenha_parte_cima(){
	//desenha tronco_1
	glColor3f(1.0f, 0.5f, 1.0f);
	glTranslatef(tronco_1.get_largura() / 2, 0.0f, 0.0f);
	glPushMatrix();
		glScalef(tronco_1.get_largura(), tronco_1.get_altura(), tronco_1.get_profundidade());
		glutSolidCube(1.0f);
	glPopMatrix();

	//desenha a espinha_d_1
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(tronco_1.get_largura() / 2, 0.0f, 0.0f);
	glRotatef(espinha_d_1.get_rotacao_x(), 1, 0, 0);
	glRotatef(espinha_d_1.get_rotacao_y(), 0, 1, 0);
	glRotatef(espinha_d_1.get_rotacao_z(), 0, 0, 1);
	desenha_junta();

	//desenha tronco_2
	glColor3f(1.0f, 0.5f, 1.0f);
	glTranslatef(tronco_2.get_largura() / 2, 0.0f, 0.0f);
	glPushMatrix();
		glScalef(tronco_2.get_largura(), tronco_2.get_altura(), tronco_2.get_profundidade());
		glutSolidCube(1.0f);
	glPopMatrix();

	//desenha a espinha_d_2
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(tronco_2.get_largura() / 2, 0.0f, 0.0f);
	glRotatef(espinha_d_2.get_rotacao_x(), 1, 0, 0);
	glRotatef(espinha_d_2.get_rotacao_y(), 0, 1, 0);
	glRotatef(espinha_d_2.get_rotacao_z(), 0, 0, 1);
	desenha_junta();



	//desenha tronco_3
	glColor3f(1.0f, 0.5f, 1.0f);
	glTranslatef(tronco_3.get_largura() / 2, 0.0f, 0.0f);
	glPushMatrix();
		glScalef(tronco_3.get_largura(), tronco_3.get_altura(), tronco_3.get_profundidade());
		glutSolidCube(1.0f);
	glPopMatrix();

	//desenha a espinha_d_3
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(tronco_3.get_largura() / 2, 0.0f, 0.0f);
	glRotatef(espinha_d_3.get_rotacao_x(), 1, 0, 0);
	glRotatef(espinha_d_3.get_rotacao_y(), 0, 1, 0);
	glRotatef(espinha_d_3.get_rotacao_z(), 0, 0, 1);
	desenha_junta();

	glPushMatrix();
		//desenha pescoco
		glColor3f(1.0f, 0.5f, 1.0f);
		glTranslatef(pescoco.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(pescoco.get_largura(), pescoco.get_altura(), pescoco.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

		//desenha junta_pescoco
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(pescoco.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(junta_pescoco.get_rotacao_x(), 1, 0, 0);
		glRotatef(junta_pescoco.get_rotacao_y(), 0, 1, 0);
		glRotatef(junta_pescoco.get_rotacao_z(), 0, 0, 1);
		desenha_junta();

		//desenha cabeca
		glColor3f(1.0f, 0.5f, 1.0f);
		glTranslatef(cabeca.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(cabeca.get_largura(), cabeca.get_altura(), cabeca.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

	glPopMatrix();

	glPushMatrix();

		glRotatef(90.0f, 0.0f, 0.0f, 1.0f);

		//desenha saboneteira_d
		glColor3f(1.0f, 0.5f, 1.0f);
		glTranslatef(saboneteira_d.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(saboneteira_d.get_largura(), saboneteira_d.get_altura(), saboneteira_d.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

		//desenha a ombro_d
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(saboneteira_d.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(ombro_d.get_rotacao_x(), 1, 0, 0);
		glRotatef(ombro_d.get_rotacao_y(), 0, 1, 0);
		glRotatef(ombro_d.get_rotacao_z(), 0, 0, 1);
		desenha_junta();

		//desenha braco_d
		glColor3f(1.0f, 0.5f, 1.0f);
		glTranslatef(braco_d.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(braco_d.get_largura(), braco_d.get_altura(), braco_d.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

		//desenha a cotovelo_d
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(braco_d.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(cotovelo_d.get_rotacao_x(), 1, 0, 0);
		glRotatef(cotovelo_d.get_rotacao_y(), 0, 1, 0);
		glRotatef(cotovelo_d.get_rotacao_z(), 0, 0, 1);
		desenha_junta();

		//desenha antebraco_d
		glColor3f(1.0f, 0.5f, 1.0f);
		glTranslatef(antebraco_d.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(antebraco_d.get_largura(), antebraco_d.get_altura(), antebraco_d.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

		//desenha a punho
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(antebraco_d.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(pulso_d.get_rotacao_x(), 1, 0, 0);
		glRotatef(pulso_d.get_rotacao_y(), 0, 1, 0);
		glRotatef(pulso_d.get_rotacao_z(), 0, 0, 1);
		desenha_junta();

		//desenha mao_d
		glColor3f(1.0f, 0.5f, 1.0f);
		glTranslatef(mao_d.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(mao_d.get_largura(), mao_d.get_altura(), mao_d.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);

	//desenha saboneteira_d
	glColor3f(1.0f, 0.5f, 1.0f);
	glTranslatef(saboneteira_e.get_largura() / 2, 0.0f, 0.0f);
	glPushMatrix();
		glScalef(saboneteira_e.get_largura(), saboneteira_e.get_altura(), saboneteira_e.get_profundidade());
		glutSolidCube(1.0f);
	glPopMatrix();

	//desenha a ombro_d
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(saboneteira_e.get_largura() / 2, 0.0f, 0.0f);
	glRotatef(ombro_e.get_rotacao_x(), 1, 0, 0);
	glRotatef(ombro_e.get_rotacao_y(), 0, 1, 0);
	glRotatef(ombro_e.get_rotacao_z(), 0, 0, 1);
	desenha_junta();

	//desenha braco_d
	glColor3f(1.0f, 0.5f, 1.0f);
	glTranslatef(braco_e.get_largura() / 2, 0.0f, 0.0f);
	glPushMatrix();
		glScalef(braco_e.get_largura(), braco_e.get_altura(), braco_e.get_profundidade());
		glutSolidCube(1.0f);
	glPopMatrix();

	//desenha a cotovelo_d
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(braco_e.get_largura() / 2, 0.0f, 0.0f);
	glRotatef(cotovelo_e.get_rotacao_x(), 1, 0, 0);
	glRotatef(cotovelo_e.get_rotacao_y(), 0, 1, 0);
	glRotatef(cotovelo_e.get_rotacao_z(), 0, 0, 1);
	desenha_junta();

	//desenha antebraco_d
	glColor3f(1.0f, 0.5f, 1.0f);
	glTranslatef(antebraco_e.get_largura() / 2, 0.0f, 0.0f);
	glPushMatrix();
		glScalef(antebraco_e.get_largura(), antebraco_e.get_altura(), antebraco_e.get_profundidade());
		glutSolidCube(1.0f);
	glPopMatrix();

	//desenha a punho
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(antebraco_e.get_largura() / 2, 0.0f, 0.0f);
	glRotatef(pulso_e.get_rotacao_x(), 1, 0, 0);
	glRotatef(pulso_e.get_rotacao_y(), 0, 1, 0);
	glRotatef(pulso_e.get_rotacao_z(), 0, 0, 1);
	desenha_junta();

	//desenha mao_d
	glColor3f(1.0f, 0.5f, 1.0f);
	glTranslatef(mao_e.get_largura() / 2, 0.0f, 0.0f);
	glPushMatrix();
		glScalef(mao_e.get_largura(), mao_e.get_altura(), mao_e.get_profundidade());
		glutSolidCube(1.0f);
	glPopMatrix();

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
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(quadril.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(virilha_d.get_rotacao_x(), 1, 0, 0);
		glRotatef(virilha_d.get_rotacao_y(), 0, 1, 0);
		glRotatef(virilha_d.get_rotacao_z(), 0, 0, 1);
		desenha_junta();

		//desenha perna
		glColor3f(1.0f, 0.5f, 1.0f);
		glTranslatef(perna_d.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(perna_d.get_largura(), perna_d.get_altura(), perna_d.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

		//desenha o joelho direito
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(perna_d.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(joelho_d.get_rotacao_x(), 1, 0, 0);
		glRotatef(joelho_d.get_rotacao_y(), 0, 1, 0);
		glRotatef(joelho_d.get_rotacao_z(), 0, 0, 1);
		desenha_junta();

		//desenha canela direita
		glColor3f(1.0f, 0.5f, 1.0f);
		glTranslatef(canela_d.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(canela_d.get_largura(), canela_d.get_altura(), canela_d.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

		//desenha o tornozelo direito
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(canela_d.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(tornozelo_d.get_rotacao_x(), 1, 0, 0);
		glRotatef(tornozelo_d.get_rotacao_y(), 0, 1, 0);
		glRotatef(tornozelo_d.get_rotacao_z(), 0, 0, 1);
		desenha_junta();

		//desenha pe direita
		glColor3f(1.0f, 0.5f, 1.0f);
		glTranslatef(pe_d.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(pe_d.get_largura(), pe_d.get_altura(), pe_d.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

		//desenha o ponta pe direito
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(pe_d.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(ponta_pe_d.get_rotacao_x(), 1, 0, 0);
		glRotatef(ponta_pe_d.get_rotacao_y(), 0, 1, 0);
		glRotatef(ponta_pe_d.get_rotacao_z(), 0, 0, 1);
		desenha_junta();

		//desenha dedos direita
		glColor3f(1.0f, 0.5f, 1.0f);
		glTranslatef(dedos_d.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(dedos_d.get_largura(), dedos_d.get_altura(), dedos_d.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();





	glPopMatrix();

	//desenha a virilha_e
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(-(quadril.get_largura() / 2), 0.0f, 0.0f);
		glRotatef(virilha_e.get_rotacao_x(), 1, 0, 0);
		glRotatef(virilha_e.get_rotacao_y(), 0, 1, 0);
		glRotatef(virilha_e.get_rotacao_z(), 0, 0, 1);
		desenha_junta();

		// //desenha esquerda
		glColor3f(1.0f, 0.5f, 1.0f);
		glTranslatef(perna_e.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(perna_e.get_largura(), perna_e.get_altura(), perna_e.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

		//desenha o joelho esquerdo
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(perna_e.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(joelho_e.get_rotacao_x(), 1, 0, 0);
		glRotatef(joelho_e.get_rotacao_y(), 0, 1, 0);
		glRotatef(joelho_e.get_rotacao_z(), 0, 0, 1);
		desenha_junta();

		//desenha canela esquerda
		glColor3f(1.0f, 0.5f, 1.0f);
		glTranslatef(canela_e.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(canela_e.get_largura(), canela_e.get_altura(), canela_e.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

		//desenha o tornozelo esquerdo
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(canela_e.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(tornozelo_e.get_rotacao_x(), 1, 0, 0);
		glRotatef(tornozelo_e.get_rotacao_y(), 0, 1, 0);
		glRotatef(tornozelo_e.get_rotacao_z(), 0, 0, 1);
		desenha_junta();

		//desenha pe esquerdo
		glColor3f(1.0f, 0.5f, 1.0f);
		glTranslatef(pe_e.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(pe_e.get_largura(), pe_e.get_altura(), pe_e.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

		//desenha o ponta pe direito
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(pe_e.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(ponta_pe_e.get_rotacao_x(), 1, 0, 0);
		glRotatef(ponta_pe_e.get_rotacao_y(), 0, 1, 0);
		glRotatef(ponta_pe_e.get_rotacao_z(), 0, 0, 1);
		desenha_junta();

		//desenha dedos direita
		glColor3f(1.0f, 0.5f, 1.0f);
		glTranslatef(dedos_e.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(dedos_e.get_largura(), dedos_e.get_altura(), dedos_e.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

	glPopMatrix();
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


	//desenha a cintura
	glColor3f(1.0f, 1.0f, 1.0f);
	glTranslatef(cintura.get_deslocamento_x(), cintura.get_deslocamento_y(), cintura.get_deslocamento_z());
	glRotatef(cintura.get_rotacao_x(), 1, 0, 0);
	glRotatef(cintura.get_rotacao_y(), 0, 1, 0);
	glRotatef(cintura.get_rotacao_z(), 0, 0, 1);
	desenha_junta();

	glPushMatrix();
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
		desenha_parte_cima();
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

	usleep(100);

	if(key == 100){
		cintura.set_deslocamento_y(cintura.get_deslocamento_y() + 3);
	}else
	if(key == 97){
		cintura.set_deslocamento_y(cintura.get_deslocamento_y() - 3);
	}else
	if(key == 119){
		cintura.set_rotacao_y(cintura.get_rotacao_y() + 3);
	}else
	if(key == 115){
		cintura.set_rotacao_y(cintura.get_rotacao_y() - 3);
	}else
	if(key == 103){

		if(joelho_sentido == 0){
			if(virilha_d.get_rotacao_x() > -45){
				virilha_d.set_rotacao_x(virilha_d.get_rotacao_x() - 3);
			}else
			if(virilha_d.get_rotacao_x() <= -45){
				if(joelho_d.get_rotacao_y() <= 90){
					joelho_d.set_rotacao_y(joelho_d.get_rotacao_y() + 3);
				}else{
					joelho_sentido = 1;
				}
			}
		}else{
			if(virilha_d.get_rotacao_x() < 0){
				virilha_d.set_rotacao_x(virilha_d.get_rotacao_x() + 3);
			}else
			if(virilha_d.get_rotacao_x() == 0){
				if(joelho_d.get_rotacao_y()  >= 0){
					joelho_d.set_rotacao_y(joelho_d.get_rotacao_y() - 3);
				}else{
					joelho_sentido = 0;
				}
			}
		}
	}




	glutPostRedisplay();
}

// Programa Principal
int main(int argc, char** argv)
{

	virilha_d.set_rotacao_z(-90.0f);
	virilha_e.set_rotacao_z(-90.0f);

	tornozelo_d.set_rotacao_y(-90.0f);
	tornozelo_e.set_rotacao_y(-90.0f);

	ombro_d.set_rotacao_z(90.0f);
	ombro_e.set_rotacao_y(-90.0f);

	//abrir perna(eixo z)
	//levantar perna(eixo x)
	// virilha_d.set_rotacao_x(-45.0f);
    //
	// joelho_d.set_rotacao_y(90.0f);

	//cintura.set_rotacao_y(90.0f);

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

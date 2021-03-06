// Este código está baseado nos exemplos disponíveis no livro
// "OpenGL SuperBible", 2nd Edition, de Richard S. e Wright Jr.

#include <GL/glut.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include "modelo.hpp"
#include "move.hpp"    // needed to sleep

using namespace std;

GLfloat angle, fAspect;

float raio_juntas = 2.0f;
int joelho_sentido = 0;
int anim_pos = 0;
const int max_frames = 62;

int CTRL = 0;
int ALT = 0;
int SHIFT = 0;

int play = 0;

ofstream matriz_s;

Move animation[19][max_frames];

//Juntas
Move cintura_s;
Move virilha_d_s;
Move virilha_e_s;
Move joelho_d_s;
Move joelho_e_s;
Move tornozelo_d_s;
Move tornozelo_e_s;
Move ponta_pe_d_s;
Move ponta_pe_e_s;
Move espinha_d_1_s;
Move espinha_d_2_s;
Move espinha_d_3_s;
Move ombro_d_s;
Move ombro_e_s;
Move cotovelo_d_s;
Move cotovelo_e_s;
Move pulso_d_s;
Move pulso_e_s;
Move junta_pescoco_s;

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
Modelo ombro_d(3.0f);
Modelo ombro_e(3.0f);
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
Modelo braco_d(16.0f, 5.0f, 5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

Modelo antebraco_e(16.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo antebraco_d(16.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

Modelo mao_e(4.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
Modelo mao_d(4.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

void load_animation(){
	anim_pos = 0;
	ifstream in;
	in.open("saida.txt", fstream::in);
	float t_x;
	float t_y;
	float t_z;
	float r_x;
	float r_y;
	float r_z;

	for(int j = 0; j < max_frames; j++){
		for(int i = 0; i < 19; i++){
			in >> t_x;
			in >> t_y;
			in >> t_z;
			in >> r_x;
			in >> r_y;
			in >> r_z;

			animation[i][j].t_x = t_x;
			animation[i][j].t_y = t_y;
			animation[i][j].t_z = t_z;
			animation[i][j].r_x = r_x;
			animation[i][j].r_y = r_y;
			animation[i][j].r_z = r_z;

		}
	}
}


void animate(){
	cintura.set_deslocamento_x(cintura.get_deslocamento_x() + animation[0][anim_pos].t_x);
	cintura.set_deslocamento_z(cintura.get_deslocamento_y() + animation[0][anim_pos].t_y);
	cintura.set_deslocamento_z(cintura.get_deslocamento_z() + animation[0][anim_pos].t_z);
	cintura.set_rotacao_x(cintura.get_rotacao_x() + animation[0][anim_pos].r_x);
	cintura.set_rotacao_y(cintura.get_rotacao_y() + animation[0][anim_pos].r_y);
	cintura.set_rotacao_z(cintura.get_rotacao_z() + animation[0][anim_pos].r_z);

	virilha_d.set_deslocamento_x(virilha_d.get_deslocamento_x() + animation[1][anim_pos].t_x);
	virilha_d.set_deslocamento_z(virilha_d.get_deslocamento_y() + animation[1][anim_pos].t_y);
	virilha_d.set_deslocamento_z(virilha_d.get_deslocamento_z() + animation[1][anim_pos].t_z);
	virilha_d.set_rotacao_x(virilha_d.get_rotacao_x() + animation[1][anim_pos].r_x);
	virilha_d.set_rotacao_y(virilha_d.get_rotacao_y() + animation[1][anim_pos].r_y);
	virilha_d.set_rotacao_z(virilha_d.get_rotacao_z() + animation[1][anim_pos].r_z);

	virilha_e.set_deslocamento_x(virilha_e.get_deslocamento_x() + animation[2][anim_pos].t_x);
	virilha_e.set_deslocamento_z(virilha_e.get_deslocamento_y() + animation[2][anim_pos].t_y);
	virilha_e.set_deslocamento_z(virilha_e.get_deslocamento_z() + animation[2][anim_pos].t_z);
	virilha_e.set_rotacao_x(virilha_e.get_rotacao_x() + animation[2][anim_pos].r_x);
	virilha_e.set_rotacao_y(virilha_e.get_rotacao_y() + animation[2][anim_pos].r_y);
	virilha_e.set_rotacao_z(virilha_e.get_rotacao_z() + animation[2][anim_pos].r_z);

	joelho_d.set_deslocamento_x(joelho_d.get_deslocamento_x() + animation[3][anim_pos].t_x);
	joelho_d.set_deslocamento_z(joelho_d.get_deslocamento_y() + animation[3][anim_pos].t_y);
	joelho_d.set_deslocamento_z(joelho_d.get_deslocamento_z() + animation[3][anim_pos].t_z);
	joelho_d.set_rotacao_x(joelho_d.get_rotacao_x() + animation[3][anim_pos].r_x);
	joelho_d.set_rotacao_y(joelho_d.get_rotacao_y() + animation[3][anim_pos].r_y);
	joelho_d.set_rotacao_z(joelho_d.get_rotacao_z() + animation[3][anim_pos].r_z);

	joelho_e.set_deslocamento_x(joelho_e.get_deslocamento_x() + animation[4][anim_pos].t_x);
	joelho_e.set_deslocamento_z(joelho_e.get_deslocamento_y() + animation[4][anim_pos].t_y);
	joelho_e.set_deslocamento_z(joelho_e.get_deslocamento_z() + animation[4][anim_pos].t_z);
	joelho_e.set_rotacao_x(joelho_e.get_rotacao_x() + animation[4][anim_pos].r_x);
	joelho_e.set_rotacao_y(joelho_e.get_rotacao_y() + animation[4][anim_pos].r_y);
	joelho_e.set_rotacao_z(joelho_e.get_rotacao_z() + animation[4][anim_pos].r_z);

	tornozelo_d.set_deslocamento_x(tornozelo_d.get_deslocamento_x() + animation[5][anim_pos].t_x);
	tornozelo_d.set_deslocamento_z(tornozelo_d.get_deslocamento_y() + animation[5][anim_pos].t_y);
	tornozelo_d.set_deslocamento_z(tornozelo_d.get_deslocamento_z() + animation[5][anim_pos].t_z);
	tornozelo_d.set_rotacao_x(tornozelo_d.get_rotacao_x() + animation[5][anim_pos].r_x);
	tornozelo_d.set_rotacao_y(tornozelo_d.get_rotacao_y() + animation[5][anim_pos].r_y);
	tornozelo_d.set_rotacao_z(tornozelo_d.get_rotacao_z() + animation[5][anim_pos].r_z);

	tornozelo_e.set_deslocamento_x(tornozelo_e.get_deslocamento_x() + animation[6][anim_pos].t_x);
	tornozelo_e.set_deslocamento_z(tornozelo_e.get_deslocamento_y() + animation[6][anim_pos].t_y);
	tornozelo_e.set_deslocamento_z(tornozelo_e.get_deslocamento_z() + animation[6][anim_pos].t_z);
	tornozelo_e.set_rotacao_x(tornozelo_e.get_rotacao_x() + animation[6][anim_pos].r_x);
	tornozelo_e.set_rotacao_y(tornozelo_e.get_rotacao_y() + animation[6][anim_pos].r_y);
	tornozelo_e.set_rotacao_z(tornozelo_e.get_rotacao_z() + animation[6][anim_pos].r_z);

	ponta_pe_d.set_deslocamento_x(ponta_pe_d.get_deslocamento_x() + animation[7][anim_pos].t_x);
	ponta_pe_d.set_deslocamento_z(ponta_pe_d.get_deslocamento_y() + animation[7][anim_pos].t_y);
	ponta_pe_d.set_deslocamento_z(ponta_pe_d.get_deslocamento_z() + animation[7][anim_pos].t_z);
	ponta_pe_d.set_rotacao_x(ponta_pe_d.get_rotacao_x() + animation[7][anim_pos].r_x);
	ponta_pe_d.set_rotacao_y(ponta_pe_d.get_rotacao_y() + animation[7][anim_pos].r_y);
	ponta_pe_d.set_rotacao_z(ponta_pe_d.get_rotacao_z() + animation[7][anim_pos].r_z);

	ponta_pe_e.set_deslocamento_x(ponta_pe_e.get_deslocamento_x() + animation[8][anim_pos].t_x);
	ponta_pe_e.set_deslocamento_z(ponta_pe_e.get_deslocamento_y() + animation[8][anim_pos].t_y);
	ponta_pe_e.set_deslocamento_z(ponta_pe_e.get_deslocamento_z() + animation[8][anim_pos].t_z);
	ponta_pe_e.set_rotacao_x(ponta_pe_e.get_rotacao_x() + animation[8][anim_pos].r_x);
	ponta_pe_e.set_rotacao_y(ponta_pe_e.get_rotacao_y() + animation[8][anim_pos].r_y);
	ponta_pe_e.set_rotacao_z(ponta_pe_e.get_rotacao_z() + animation[8][anim_pos].r_z);

	espinha_d_1.set_deslocamento_x(espinha_d_1.get_deslocamento_x() + animation[9][anim_pos].t_x);
	espinha_d_1.set_deslocamento_z(espinha_d_1.get_deslocamento_y() + animation[9][anim_pos].t_y);
	espinha_d_1.set_deslocamento_z(espinha_d_1.get_deslocamento_z() + animation[9][anim_pos].t_z);
	espinha_d_1.set_rotacao_x(espinha_d_1.get_rotacao_x() + animation[9][anim_pos].r_x);
	espinha_d_1.set_rotacao_y(espinha_d_1.get_rotacao_y() + animation[9][anim_pos].r_y);
	espinha_d_1.set_rotacao_z(espinha_d_1.get_rotacao_z() + animation[9][anim_pos].r_z);

	espinha_d_2.set_deslocamento_x(espinha_d_2.get_deslocamento_x() + animation[10][anim_pos].t_x);
	espinha_d_2.set_deslocamento_z(espinha_d_2.get_deslocamento_y() + animation[10][anim_pos].t_y);
	espinha_d_2.set_deslocamento_z(espinha_d_2.get_deslocamento_z() + animation[10][anim_pos].t_z);
	espinha_d_2.set_rotacao_x(espinha_d_2.get_rotacao_x() + animation[10][anim_pos].r_x);
	espinha_d_2.set_rotacao_y(espinha_d_2.get_rotacao_y() + animation[10][anim_pos].r_y);
	espinha_d_2.set_rotacao_z(espinha_d_2.get_rotacao_z() + animation[10][anim_pos].r_z);

	espinha_d_3.set_deslocamento_x(espinha_d_3.get_deslocamento_x() + animation[11][anim_pos].t_x);
	espinha_d_3.set_deslocamento_z(espinha_d_3.get_deslocamento_y() + animation[11][anim_pos].t_y);
	espinha_d_3.set_deslocamento_z(espinha_d_3.get_deslocamento_z() + animation[11][anim_pos].t_z);
	espinha_d_3.set_rotacao_x(espinha_d_3.get_rotacao_x() + animation[11][anim_pos].r_x);
	espinha_d_3.set_rotacao_y(espinha_d_3.get_rotacao_y() + animation[11][anim_pos].r_y);
	espinha_d_3.set_rotacao_z(espinha_d_3.get_rotacao_z() + animation[11][anim_pos].r_z);

	ombro_d.set_deslocamento_x(ombro_d.get_deslocamento_x() + animation[12][anim_pos].t_x);
	ombro_d.set_deslocamento_z(ombro_d.get_deslocamento_y() + animation[12][anim_pos].t_y);
	ombro_d.set_deslocamento_z(ombro_d.get_deslocamento_z() + animation[12][anim_pos].t_z);
	ombro_d.set_rotacao_x(ombro_d.get_rotacao_x() + animation[12][anim_pos].r_x);
	ombro_d.set_rotacao_y(ombro_d.get_rotacao_y() + animation[12][anim_pos].r_y);
	ombro_d.set_rotacao_z(ombro_d.get_rotacao_z() + animation[12][anim_pos].r_z);

	ombro_e.set_deslocamento_x(ombro_e.get_deslocamento_x() + animation[13][anim_pos].t_x);
	ombro_e.set_deslocamento_z(ombro_e.get_deslocamento_y() + animation[13][anim_pos].t_y);
	ombro_e.set_deslocamento_z(ombro_e.get_deslocamento_z() + animation[13][anim_pos].t_z);
	ombro_e.set_rotacao_x(ombro_e.get_rotacao_x() + animation[13][anim_pos].r_x);
	ombro_e.set_rotacao_y(ombro_e.get_rotacao_y() + animation[13][anim_pos].r_y);
	ombro_e.set_rotacao_z(ombro_e.get_rotacao_z() + animation[13][anim_pos].r_z);

	cotovelo_d.set_deslocamento_x(cotovelo_d.get_deslocamento_x() + animation[14][anim_pos].t_x);
	cotovelo_d.set_deslocamento_z(cotovelo_d.get_deslocamento_y() + animation[14][anim_pos].t_y);
	cotovelo_d.set_deslocamento_z(cotovelo_d.get_deslocamento_z() + animation[14][anim_pos].t_z);
	cotovelo_d.set_rotacao_x(cotovelo_d.get_rotacao_x() + animation[14][anim_pos].r_x);
	cotovelo_d.set_rotacao_y(cotovelo_d.get_rotacao_y() + animation[14][anim_pos].r_y);
	cotovelo_d.set_rotacao_z(cotovelo_d.get_rotacao_z() + animation[14][anim_pos].r_z);

	cotovelo_e.set_deslocamento_x(cotovelo_e.get_deslocamento_x() + animation[15][anim_pos].t_x);
	cotovelo_e.set_deslocamento_z(cotovelo_e.get_deslocamento_y() + animation[15][anim_pos].t_y);
	cotovelo_e.set_deslocamento_z(cotovelo_e.get_deslocamento_z() + animation[15][anim_pos].t_z);
	cotovelo_e.set_rotacao_x(cotovelo_e.get_rotacao_x() + animation[15][anim_pos].r_x);
	cotovelo_e.set_rotacao_y(cotovelo_e.get_rotacao_y() + animation[15][anim_pos].r_y);
	cotovelo_e.set_rotacao_z(cotovelo_e.get_rotacao_z() + animation[15][anim_pos].r_z);

	pulso_d.set_deslocamento_x(pulso_d.get_deslocamento_x() + animation[16][anim_pos].t_x);
	pulso_d.set_deslocamento_z(pulso_d.get_deslocamento_y() + animation[16][anim_pos].t_y);
	pulso_d.set_deslocamento_z(pulso_d.get_deslocamento_z() + animation[16][anim_pos].t_z);
	pulso_d.set_rotacao_x(pulso_d.get_rotacao_x() + animation[16][anim_pos].r_x);
	pulso_d.set_rotacao_y(pulso_d.get_rotacao_y() + animation[16][anim_pos].r_y);
	pulso_d.set_rotacao_z(pulso_d.get_rotacao_z() + animation[16][anim_pos].r_z);

	pulso_e.set_deslocamento_x(pulso_e.get_deslocamento_x() + animation[17][anim_pos].t_x);
	pulso_e.set_deslocamento_z(pulso_e.get_deslocamento_y() + animation[17][anim_pos].t_y);
	pulso_e.set_deslocamento_z(pulso_e.get_deslocamento_z() + animation[17][anim_pos].t_z);
	pulso_e.set_rotacao_x(pulso_e.get_rotacao_x() + animation[17][anim_pos].r_x);
	pulso_e.set_rotacao_y(pulso_e.get_rotacao_y() + animation[17][anim_pos].r_y);
	pulso_e.set_rotacao_z(pulso_e.get_rotacao_z() + animation[17][anim_pos].r_z);

	junta_pescoco.set_deslocamento_x(junta_pescoco.get_deslocamento_x() + animation[18][anim_pos].t_x);
	junta_pescoco.set_deslocamento_z(junta_pescoco.get_deslocamento_y() + animation[18][anim_pos].t_y);
	junta_pescoco.set_deslocamento_z(junta_pescoco.get_deslocamento_z() + animation[18][anim_pos].t_z);
	junta_pescoco.set_rotacao_x(junta_pescoco.get_rotacao_x() + animation[18][anim_pos].r_x);
	junta_pescoco.set_rotacao_y(junta_pescoco.get_rotacao_y() + animation[18][anim_pos].r_y);
	junta_pescoco.set_rotacao_z(junta_pescoco.get_rotacao_z() + animation[18][anim_pos].r_z);
}

void desenha_junta(Modelo m){
	glPushMatrix();
		glScalef(m.get_largura(), m.get_largura(), m.get_largura());
		glutSolidSphere(1.0f, 20, 20);
	glPopMatrix();
}

void desenha_parte_cima(){
	//desenha tronco_1
	glColor3f(0.0f, 0.0f, 1.0f);
	glTranslatef(tronco_1.get_largura() / 2, 0.0f, 0.0f);
	glPushMatrix();
		glScalef(tronco_1.get_largura(), tronco_1.get_altura(), tronco_1.get_profundidade());
		glutSolidCube(1.0f);
	glPopMatrix();

	//desenha a espinha_d_1
	glColor3f(0.0f, 0.0f, 1.0f);
	glTranslatef(tronco_1.get_largura() / 2, 0.0f, 0.0f);
	glRotatef(espinha_d_1.get_rotacao_x(), 1, 0, 0);
	glRotatef(espinha_d_1.get_rotacao_y(), 0, 1, 0);
	glRotatef(espinha_d_1.get_rotacao_z(), 0, 0, 1);
	desenha_junta(espinha_d_1);

	//desenha tronco_2
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(tronco_2.get_largura() / 2, 0.0f, 0.0f);
	glPushMatrix();
		glScalef(tronco_2.get_largura(), tronco_2.get_altura(), tronco_2.get_profundidade());
		glutSolidCube(1.0f);
	glPopMatrix();

	//desenha a espinha_d_2
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(tronco_2.get_largura() / 2, 0.0f, 0.0f);
	glRotatef(espinha_d_2.get_rotacao_x(), 1, 0, 0);
	glRotatef(espinha_d_2.get_rotacao_y(), 0, 1, 0);
	glRotatef(espinha_d_2.get_rotacao_z(), 0, 0, 1);
	desenha_junta(espinha_d_2);



	//desenha tronco_3
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(tronco_3.get_largura() / 2, 0.0f, 0.0f);
	glPushMatrix();
		glScalef(tronco_3.get_largura(), tronco_3.get_altura(), tronco_3.get_profundidade());
		glutSolidCube(1.0f);
	glPopMatrix();

	//desenha a espinha_d_3
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(tronco_3.get_largura() / 2, 0.0f, 0.0f);
	glRotatef(espinha_d_3.get_rotacao_x(), 1, 0, 0);
	glRotatef(espinha_d_3.get_rotacao_y(), 0, 1, 0);
	glRotatef(espinha_d_3.get_rotacao_z(), 0, 0, 1);
	desenha_junta(espinha_d_3);

	glPushMatrix();
		//desenha pescoco
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(pescoco.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(pescoco.get_largura(), pescoco.get_altura(), pescoco.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

		//desenha junta_pescoco
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(pescoco.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(junta_pescoco.get_rotacao_x(), 1, 0, 0);
		glRotatef(junta_pescoco.get_rotacao_y(), 0, 1, 0);
		glRotatef(junta_pescoco.get_rotacao_z(), 0, 0, 1);
		desenha_junta(junta_pescoco);

		//desenha cabeca
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(cabeca.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(cabeca.get_largura(), cabeca.get_altura(), cabeca.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

	glPopMatrix();

	glPushMatrix();

		glRotatef(90.0f, 0.0f, 0.0f, 1.0f);

		//desenha saboneteira_d
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(saboneteira_d.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(saboneteira_d.get_largura(), saboneteira_d.get_altura(), saboneteira_d.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

		//desenha a ombro_d
		glColor3f(0.0f, 0.0f, 1.0f);
		glTranslatef(saboneteira_d.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(ombro_d.get_rotacao_x(), 1, 0, 0);
		glRotatef(ombro_d.get_rotacao_y(), 0, 1, 0);
		glRotatef(ombro_d.get_rotacao_z(), 0, 0, 1);
		desenha_junta(ombro_d);

		//desenha braco_d
		glColor3f(0.0f, 0.0f, 1.0f);
		glTranslatef(braco_d.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(braco_d.get_largura(), braco_d.get_altura(), braco_d.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

		//desenha a cotovelo_d
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(braco_d.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(cotovelo_d.get_rotacao_x(), 1, 0, 0);
		glRotatef(cotovelo_d.get_rotacao_y(), 0, 1, 0);
		glRotatef(cotovelo_d.get_rotacao_z(), 0, 0, 1);
		desenha_junta(cotovelo_d);

		//desenha antebraco_d
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(antebraco_d.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(antebraco_d.get_largura(), antebraco_d.get_altura(), antebraco_d.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

		//desenha a punho
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(antebraco_d.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(pulso_d.get_rotacao_x(), 1, 0, 0);
		glRotatef(pulso_d.get_rotacao_y(), 0, 1, 0);
		glRotatef(pulso_d.get_rotacao_z(), 0, 0, 1);
		desenha_junta(pulso_d);

		//desenha mao_d
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(mao_d.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(mao_d.get_largura(), mao_d.get_altura(), mao_d.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90.0f, 0.0f, 0.0f, 1.0f);

	//desenha saboneteira_d
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(saboneteira_e.get_largura() / 2, 0.0f, 0.0f);
	glPushMatrix();
		glScalef(saboneteira_e.get_largura(), saboneteira_e.get_altura(), saboneteira_e.get_profundidade());
		glutSolidCube(1.0f);
	glPopMatrix();

	//desenha a ombro_e
	glColor3f(0.0f, 0.0f, 1.0f);
	glTranslatef(saboneteira_e.get_largura() / 2, 0.0f, 0.0f);
	glRotatef(ombro_e.get_rotacao_x(), 1, 0, 0);
	glRotatef(ombro_e.get_rotacao_y(), 0, 1, 0);
	glRotatef(ombro_e.get_rotacao_z(), 0, 0, 1);
	desenha_junta(ombro_e);

	//desenha braco_d
	glColor3f(0.0f, 0.0f, 1.0f);
	glTranslatef(braco_e.get_largura() / 2, 0.0f, 0.0f);
	glPushMatrix();
		glScalef(braco_e.get_largura(), braco_e.get_altura(), braco_e.get_profundidade());
		glutSolidCube(1.0f);
	glPopMatrix();

	//desenha a cotovelo_e
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(braco_e.get_largura() / 2, 0.0f, 0.0f);
	glRotatef(cotovelo_e.get_rotacao_x(), 1, 0, 0);
	glRotatef(cotovelo_e.get_rotacao_y(), 0, 1, 0);
	glRotatef(cotovelo_e.get_rotacao_z(), 0, 0, 1);
	desenha_junta(cotovelo_e);

	//desenha antebraco_d
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(antebraco_e.get_largura() / 2, 0.0f, 0.0f);
	glPushMatrix();
		glScalef(antebraco_e.get_largura(), antebraco_e.get_altura(), antebraco_e.get_profundidade());
		glutSolidCube(1.0f);
	glPopMatrix();

	//desenha a punho
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(antebraco_e.get_largura() / 2, 0.0f, 0.0f);
	glRotatef(pulso_e.get_rotacao_x(), 1, 0, 0);
	glRotatef(pulso_e.get_rotacao_y(), 0, 1, 0);
	glRotatef(pulso_e.get_rotacao_z(), 0, 0, 1);
	desenha_junta(pulso_e);

	//desenha mao_d
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(mao_e.get_largura() / 2, 0.0f, 0.0f);
	glPushMatrix();
		glScalef(mao_e.get_largura(), mao_e.get_altura(), mao_e.get_profundidade());
		glutSolidCube(1.0f);
	glPopMatrix();

	glPopMatrix();

}

void desenha_parte_baixo(){
	//desenha o quadril
	glColor3f(1.0f, 0.0f, 0.0f);
	glTranslatef(quadril.get_deslocamento_x(), quadril.get_deslocamento_y(), quadril.get_deslocamento_z());
	glPushMatrix();
		glScalef(quadril.get_largura(), quadril.get_altura(), quadril.get_profundidade());
		glutSolidCube(1.0f);
	glPopMatrix();

	//desenha a virilha_d
	glPushMatrix();
		glColor3f(0.0f, 0.0f, 1.0f);
		glTranslatef(quadril.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(virilha_d.get_rotacao_x(), 1, 0, 0);
		glRotatef(virilha_d.get_rotacao_y(), 0, 1, 0);
		glRotatef(virilha_d.get_rotacao_z(), 0, 0, 1);
		desenha_junta(virilha_d);

		//desenha perna
		glColor3f(0.0f, 0.0f, 1.0f);
		glTranslatef(perna_d.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(perna_d.get_largura(), perna_d.get_altura(), perna_d.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

		//desenha o joelho direito
		glColor3f(0.0f, 0.0f, 1.0f);
		glTranslatef(perna_d.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(joelho_d.get_rotacao_x(), 1, 0, 0);
		glRotatef(joelho_d.get_rotacao_y(), 0, 1, 0);
		glRotatef(joelho_d.get_rotacao_z(), 0, 0, 1);
		desenha_junta(joelho_d);

		//desenha canela direita
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(canela_d.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(canela_d.get_largura(), canela_d.get_altura(), canela_d.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

		//desenha o tornozelo direito
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(canela_d.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(tornozelo_d.get_rotacao_x(), 1, 0, 0);
		glRotatef(tornozelo_d.get_rotacao_y(), 0, 1, 0);
		glRotatef(tornozelo_d.get_rotacao_z(), 0, 0, 1);
		desenha_junta(tornozelo_d);

		//desenha pe direita
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(pe_d.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(pe_d.get_largura(), pe_d.get_altura(), pe_d.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

		//desenha o ponta pe direito
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(pe_d.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(ponta_pe_d.get_rotacao_x(), 1, 0, 0);
		glRotatef(ponta_pe_d.get_rotacao_y(), 0, 1, 0);
		glRotatef(ponta_pe_d.get_rotacao_z(), 0, 0, 1);
		desenha_junta(ponta_pe_d);

		//desenha dedos direita
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(dedos_d.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(dedos_d.get_largura(), dedos_d.get_altura(), dedos_d.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

	glPopMatrix();

	//desenha a virilha_e
	glPushMatrix();
		glColor3f(0.0f, 0.0f, 1.0f);
		glTranslatef(-(quadril.get_largura() / 2), 0.0f, 0.0f);
		glRotatef(virilha_e.get_rotacao_x(), 1, 0, 0);
		glRotatef(virilha_e.get_rotacao_y(), 0, 1, 0);
		glRotatef(virilha_e.get_rotacao_z(), 0, 0, 1);
		desenha_junta(virilha_e);

		// //desenha esquerda
		glColor3f(0.0f, 0.0f, 1.0f);
		glTranslatef(perna_e.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(perna_e.get_largura(), perna_e.get_altura(), perna_e.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

		//desenha o joelho esquerdo
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(perna_e.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(joelho_e.get_rotacao_x(), 1, 0, 0);
		glRotatef(joelho_e.get_rotacao_y(), 0, 1, 0);
		glRotatef(joelho_e.get_rotacao_z(), 0, 0, 1);
		desenha_junta(joelho_e);

		//desenha canela esquerda
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(canela_e.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(canela_e.get_largura(), canela_e.get_altura(), canela_e.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

		//desenha o tornozelo esquerdo
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(canela_e.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(tornozelo_e.get_rotacao_x(), 1, 0, 0);
		glRotatef(tornozelo_e.get_rotacao_y(), 0, 1, 0);
		glRotatef(tornozelo_e.get_rotacao_z(), 0, 0, 1);
		desenha_junta(tornozelo_e);

		//desenha pe esquerdo
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(pe_e.get_largura() / 2, 0.0f, 0.0f);
		glPushMatrix();
			glScalef(pe_e.get_largura(), pe_e.get_altura(), pe_e.get_profundidade());
			glutSolidCube(1.0f);
		glPopMatrix();

		//desenha o ponta pe direito
		glColor3f(1.0f, 0.0f, 0.0f);
		glTranslatef(pe_e.get_largura() / 2, 0.0f, 0.0f);
		glRotatef(ponta_pe_e.get_rotacao_x(), 1, 0, 0);
		glRotatef(ponta_pe_e.get_rotacao_y(), 0, 1, 0);
		glRotatef(ponta_pe_e.get_rotacao_z(), 0, 0, 1);
		desenha_junta(ponta_pe_e);

		//desenha dedos direita
		glColor3f(1.0f, 0.0f, 0.0f);
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
void Desenha(void){

	usleep(80000);

	if(play){
		if(anim_pos <= (max_frames - 1)){
			animate();
			anim_pos++;
		}
	}

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
	desenha_junta(cintura);

	glPushMatrix();
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
		desenha_parte_cima();
	glPopMatrix();

	glPushMatrix();
		desenha_parte_baixo();
	glPopMatrix();

	glutSwapBuffers();

	glutPostRedisplay();
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

void keyBoardSpecialfunc(int key, int x, int y){
	if(key == 112){
		SHIFT = 1;
	}else
	if(key == 114){
		CTRL = 1;
	}else
	if(key == 116){
		ALT = 1;
	}
}

void keyBoardSpecialUpfunc(int key, int x, int y){
	if(key == 112){
		SHIFT = 0;
	}else
	if(key == 114){
		CTRL = 0;
	}else
	if(key == 116){
		ALT = 0;
	}
}

void keyBoardfunc(unsigned char key, int x, int y){

	usleep(100);

	if(SHIFT){
		//cout << "SHIFT + " << int(key) << endl;
		if(key == 33){
			cintura.set_rotacao_x(cintura.get_rotacao_x() + 3);
		}else
		if(key == 81){
			cintura.set_rotacao_x(cintura.get_rotacao_x() - 3);
		}else
		if(key == 64){
			virilha_d.set_rotacao_x(virilha_d.get_rotacao_x() + 3);
		}else
		if(key == 87){
			virilha_d.set_rotacao_x(virilha_d.get_rotacao_x() - 3);
		}else
		if(key == 35){
			virilha_e.set_rotacao_x(virilha_e.get_rotacao_x() + 3);
		}else
		if(key == 69){
			virilha_e.set_rotacao_x(virilha_e.get_rotacao_x() - 3);
		}else
		if(key == 36){
			joelho_d.set_rotacao_x(joelho_d.get_rotacao_x() + 3);
		}else
		if(key == 82){
			joelho_d.set_rotacao_x(joelho_d.get_rotacao_x() - 3);
		}else
		if(key == 37){
			joelho_e.set_rotacao_x(joelho_e.get_rotacao_x() + 3);
		}else
		if(key == 84){
			joelho_e.set_rotacao_x(joelho_e.get_rotacao_x() - 3);
		}else
		if(key == 168){
			tornozelo_d.set_rotacao_x(tornozelo_d.get_rotacao_x() + 3);
		}else
		if(key == 89){
			tornozelo_d.set_rotacao_x(tornozelo_d.get_rotacao_x() - 3);
		}else
		if(key == 38){
			tornozelo_e.set_rotacao_x(tornozelo_e.get_rotacao_x() + 3);
		}else
		if(key == 85){
			tornozelo_e.set_rotacao_x(tornozelo_e.get_rotacao_x() - 3);
		}else
		if(key == 42){
			ponta_pe_d.set_rotacao_x(ponta_pe_d.get_rotacao_x() + 3);
		}else
		if(key == 73){
			ponta_pe_d.set_rotacao_x(ponta_pe_d.get_rotacao_x() - 3);
		}else
		if(key == 40){
			ponta_pe_e.set_rotacao_x(ponta_pe_e.get_rotacao_x() + 3);
		}else
		if(key == 79){
			ponta_pe_e.set_rotacao_x(ponta_pe_e.get_rotacao_x() - 3);
		}else
		if(key == 41){
			espinha_d_1.set_rotacao_x(espinha_d_1.get_rotacao_x() + 3);
		}else
		if(key == 80){
			espinha_d_1.set_rotacao_x(espinha_d_1.get_rotacao_x() - 3);
		}else
		if(key == 75){
			espinha_d_2.set_rotacao_x(espinha_d_2.get_rotacao_x() + 3);
		}else
		if(key == 60){
			espinha_d_2.set_rotacao_x(espinha_d_2.get_rotacao_x() - 3);
		}else
		if(key == 76){
			espinha_d_3.set_rotacao_x(espinha_d_3.get_rotacao_x() + 3);
		}else
		if(key == 62){
			espinha_d_3.set_rotacao_x(espinha_d_3.get_rotacao_x() - 3);
		}else
		if(key == 65){
			ombro_d.set_rotacao_x(ombro_d.get_rotacao_x() + 3);
		}else
		if(key == 90){
			ombro_d.set_rotacao_x(ombro_d.get_rotacao_x() - 3);
		}else
		if(key == 83){
			ombro_e.set_rotacao_x(ombro_e.get_rotacao_x() + 3);
		}else
		if(key == 88){
			ombro_e.set_rotacao_x(ombro_e.get_rotacao_x() - 3);
		}else
		if(key == 68){
			cotovelo_d.set_rotacao_x(cotovelo_d.get_rotacao_x() + 3);
		}else
		if(key == 67){
			cotovelo_d.set_rotacao_x(cotovelo_d.get_rotacao_x() - 3);
		}else
		if(key == 70){
			cotovelo_e.set_rotacao_x(cotovelo_e.get_rotacao_x() + 3);
		}else
		if(key == 86){
			cotovelo_e.set_rotacao_x(cotovelo_e.get_rotacao_x() - 3);
		}else
		if(key == 71){
			pulso_d.set_rotacao_x(pulso_d.get_rotacao_x() + 3);
		}else
		if(key == 66){
			pulso_d.set_rotacao_x(pulso_d.get_rotacao_x() - 3);
		}else
		if(key == 72){
			pulso_e.set_rotacao_x(pulso_e.get_rotacao_x() + 3);
		}else
		if(key == 78){
			pulso_e.set_rotacao_x(pulso_e.get_rotacao_x() - 3);
		}else
		if(key == 74){
			junta_pescoco.set_rotacao_x(junta_pescoco.get_rotacao_x() + 3);
		}else
		if(key == 77){
			junta_pescoco.set_rotacao_x(junta_pescoco.get_rotacao_x() - 3);
		}else
		if(key == 199){
			cintura.set_deslocamento_x(cintura.get_deslocamento_x() + 3);
		}else
		if(key == 94){
			cintura.set_deslocamento_x(cintura.get_deslocamento_x() - 3);
		}

	}else
	if(CTRL){
		//cout << "CTRL + " << int(key) << endl;
		if(key == 49){
		  cintura.set_rotacao_y(cintura.get_rotacao_y() + 3);
		}else
		if(key == 17){
		  cintura.set_rotacao_y(cintura.get_rotacao_y() - 3);
		}else
		if(key == 0){
		  virilha_d.set_rotacao_y(virilha_d.get_rotacao_y() + 3);
		}else
		if(key == 23){
		  virilha_d.set_rotacao_y(virilha_d.get_rotacao_y() - 3);
		}else
		if(key == 27){
		 virilha_e.set_rotacao_y(virilha_e.get_rotacao_y() + 3);
		}else
		if(key == 5){
		  virilha_e.set_rotacao_y(virilha_e.get_rotacao_y() - 3);
		}else
		if(key == 28){
		  joelho_d.set_rotacao_y(joelho_d.get_rotacao_y() + 3);
		}else
		if(key == 18){
		  joelho_d.set_rotacao_y(joelho_d.get_rotacao_y() - 3);
		}else
		if(key == 29){
		  joelho_e.set_rotacao_y(joelho_e.get_rotacao_y() + 3);
		}else
		if(key == 20){
		  joelho_e.set_rotacao_y(joelho_e.get_rotacao_y() - 3);
		}else
		if(key == 30){
		  tornozelo_d.set_rotacao_y(tornozelo_d.get_rotacao_y() + 3);
		}else
		if(key == 25){
		  tornozelo_d.set_rotacao_y(tornozelo_d.get_rotacao_y() - 3);
		}else
		if(key == 31){
		  tornozelo_e.set_rotacao_y(tornozelo_e.get_rotacao_y() + 3);
		}else
		if(key == 21){
		  tornozelo_e.set_rotacao_y(tornozelo_e.get_rotacao_y() - 3);
		}else
		if(key == 127){
		  ponta_pe_d.set_rotacao_y(ponta_pe_d.get_rotacao_y() + 3);
		}else
		if(key == 9){
		  ponta_pe_d.set_rotacao_y(ponta_pe_d.get_rotacao_y() - 3);
		}else
		if(key == 57){
		  ponta_pe_e.set_rotacao_y(ponta_pe_e.get_rotacao_y() + 3);
		}else
		if(key == 15){
		  ponta_pe_e.set_rotacao_y(ponta_pe_e.get_rotacao_y() - 3);
		}else
		if(key == 48){
		  espinha_d_1.set_rotacao_y(espinha_d_1.get_rotacao_y() + 3);
		}else
		if(key == 16){
		  espinha_d_1.set_rotacao_y(espinha_d_1.get_rotacao_y() - 3);
		}else
		if(key == 11){
		  espinha_d_2.set_rotacao_y(espinha_d_2.get_rotacao_y() + 3);
		}else
		if(key == 44){
		  espinha_d_2.set_rotacao_y(espinha_d_2.get_rotacao_y() - 3);
		}else
		if(key == 12){
		  espinha_d_3.set_rotacao_y(espinha_d_3.get_rotacao_y() + 3);
		}else
		if(key == 46){
		  espinha_d_3.set_rotacao_y(espinha_d_3.get_rotacao_y() - 3);
		}else
		if(key == 1){
		  ombro_d.set_rotacao_y(ombro_d.get_rotacao_y() + 3);
		}else
		if(key == 26){
		  ombro_d.set_rotacao_y(ombro_d.get_rotacao_y() - 3);
		}else
		if(key == 19){
		  ombro_e.set_rotacao_y(ombro_e.get_rotacao_y() + 3);
		}else
		if(key == 24){
		  ombro_e.set_rotacao_y(ombro_e.get_rotacao_y() - 3);
		}else
		if(key == 4){
		  cotovelo_d.set_rotacao_y(cotovelo_d.get_rotacao_y() + 3);
		}else
		if(key == 3){
		  cotovelo_d.set_rotacao_y(cotovelo_d.get_rotacao_y() - 3);
		}else
		if(key == 6){
		  cotovelo_e.set_rotacao_y(cotovelo_e.get_rotacao_y() + 3);
		}else
		if(key == 22){
		  cotovelo_e.set_rotacao_y(cotovelo_e.get_rotacao_y() - 3);
		}else
		if(key == 7){
		  pulso_d.set_rotacao_y(pulso_d.get_rotacao_y() + 3);
		}else
		if(key == 2){
		  pulso_d.set_rotacao_y(pulso_d.get_rotacao_y() - 3);
		}else
		if(key == 8){
		  pulso_e.set_rotacao_y(pulso_e.get_rotacao_y() + 3);
		}else
		if(key == 14){
		  pulso_e.set_rotacao_y(pulso_e.get_rotacao_y() - 3);
		}else
		if(key == 10){
		  junta_pescoco.set_rotacao_y(junta_pescoco.get_rotacao_y() + 3);
		}else
		if(key == 13){
		  junta_pescoco.set_rotacao_y(junta_pescoco.get_rotacao_y() - 3);
		}else
		if(key == 59){
			cintura.set_deslocamento_y(cintura.get_deslocamento_y() + 3);
		}else
		if(key == 39){
			cintura.set_deslocamento_y(cintura.get_deslocamento_y() - 3);
		}
	}else
	if(ALT){
		//cout << "ALT + " << int(key) << endl;
		if(key == 49){
		  cintura.set_rotacao_z(cintura.get_rotacao_z() + 3);
		}else
		if(key == 113){
		  cintura.set_rotacao_z(cintura.get_rotacao_z() - 3);
		}else
		if(key == 50){
		  virilha_d.set_rotacao_z(virilha_d.get_rotacao_z() + 3);
		}else
		if(key == 119){
		  virilha_d.set_rotacao_z(virilha_d.get_rotacao_z() - 3);
		}else
		if(key == 51){
		  virilha_e.set_rotacao_z(virilha_e.get_rotacao_z() + 3);
		}else
		if(key == 101){
		  virilha_e.set_rotacao_z(virilha_e.get_rotacao_z() - 3);
		}else
		if(key == 52){
		  joelho_d.set_rotacao_z(joelho_d.get_rotacao_z() + 3);
		}else
		if(key == 114){
		  joelho_d.set_rotacao_z(joelho_d.get_rotacao_z() - 3);
		}else
		if(key == 53){
		  joelho_e.set_rotacao_z(joelho_e.get_rotacao_z() + 3);
		}else
		if(key == 116){
		  joelho_e.set_rotacao_z(joelho_e.get_rotacao_z() - 3);
		}else
		if(key == 54){
		  tornozelo_d.set_rotacao_z(tornozelo_d.get_rotacao_z() + 3);
		}else
		if(key == 121){
		  tornozelo_d.set_rotacao_z(tornozelo_d.get_rotacao_z() - 3);
		}else
		if(key == 55){
		  tornozelo_e.set_rotacao_z(tornozelo_e.get_rotacao_z() + 3);
		}else
		if(key == 117){
		  tornozelo_e.set_rotacao_z(tornozelo_e.get_rotacao_z() - 3);
		}else
		if(key == 56){
		  ponta_pe_d.set_rotacao_z(ponta_pe_d.get_rotacao_z() + 3);
		}else
		if(key == 105){
		  ponta_pe_d.set_rotacao_z(ponta_pe_d.get_rotacao_z() - 3);
		}else
		if(key == 57){
		  ponta_pe_e.set_rotacao_z(ponta_pe_e.get_rotacao_z() + 3);
		}else
		if(key == 111){
		  ponta_pe_e.set_rotacao_z(ponta_pe_e.get_rotacao_z() - 3);
		}else
		if(key == 48){
		  espinha_d_1.set_rotacao_z(espinha_d_1.get_rotacao_z() + 3);
		}else
		if(key == 112){
		  espinha_d_1.set_rotacao_z(espinha_d_1.get_rotacao_z() - 3);
		}else
		if(key == 107){
		  espinha_d_2.set_rotacao_z(espinha_d_2.get_rotacao_z() + 3);
		}else
		if(key == 44){
		  espinha_d_2.set_rotacao_z(espinha_d_2.get_rotacao_z() - 3);
		}else
		if(key == 108){
		  espinha_d_3.set_rotacao_z(espinha_d_3.get_rotacao_z() + 3);
		}else
		if(key == 46){
		  espinha_d_3.set_rotacao_z(espinha_d_3.get_rotacao_z() - 3);
		}else
		if(key == 97){
		  ombro_d.set_rotacao_z(ombro_d.get_rotacao_z() + 3);
		}else
		if(key == 122){
		  ombro_d.set_rotacao_z(ombro_d.get_rotacao_z() - 3);
		}else
		if(key == 115){
		  ombro_e.set_rotacao_z(ombro_e.get_rotacao_z() + 3);
		}else
		if(key == 120){
		  ombro_e.set_rotacao_z(ombro_e.get_rotacao_z() - 3);
		}else
		if(key == 100){
		  cotovelo_d.set_rotacao_z(cotovelo_d.get_rotacao_z() + 3);
		}else
		if(key == 99){
		  cotovelo_d.set_rotacao_z(cotovelo_d.get_rotacao_z() - 3);
		}else
		if(key == 102){
		  cotovelo_e.set_rotacao_z(cotovelo_e.get_rotacao_z() + 3);
		}else
		if(key == 118){
		  cotovelo_e.set_rotacao_z(cotovelo_e.get_rotacao_z() - 3);
		}else
		if(key == 103){
		  pulso_d.set_rotacao_z(pulso_d.get_rotacao_z() + 3);
		}else
		if(key == 98){
		  pulso_d.set_rotacao_z(pulso_d.get_rotacao_z() - 3);
		}else
		if(key == 104){
		  pulso_e.set_rotacao_z(pulso_e.get_rotacao_z() + 3);
		}else
		if(key == 110){
		  pulso_e.set_rotacao_z(pulso_e.get_rotacao_z() - 3);
		}else
		if(key == 106){
		  junta_pescoco.set_rotacao_z(junta_pescoco.get_rotacao_z() + 3);
		}else
		if(key == 109){
		  junta_pescoco.set_rotacao_z(junta_pescoco.get_rotacao_z() - 3);
		}else
		if(key == 231){
			cintura.set_deslocamento_z(cintura.get_deslocamento_z() + 3);
		}else
		if(key == 126){
			cintura.set_deslocamento_z(cintura.get_deslocamento_z() - 3);
		}
	}else{
		//cout << "NORMAL " << int(key) << endl;

		if(key == 119){

			virilha_d.set_rotacao_z(-90.0f);
			virilha_e.set_rotacao_z(-90.0f);

			tornozelo_d.set_rotacao_y(-90.0f);
			tornozelo_e.set_rotacao_y(-90.0f);

			ombro_d.set_rotacao_z(90.0f);
			ombro_e.set_rotacao_z(-90.0f);


			matriz_s.open("saida.txt", ifstream::out);
		}else
		if(key == 112){
			play = 1;
		}else
		if(key == 108){
			load_animation();
		}else
		if(key == 27){
			matriz_s.close();
			exit(0);
		}else
		if(key == 13){

			cintura_s.t_x = cintura.get_deslocamento_x() - cintura_s.t_x;
			cintura_s.t_y = cintura.get_deslocamento_y() - cintura_s.t_y;
			cintura_s.t_z = cintura.get_deslocamento_z() - cintura_s.t_z;
			cintura_s.r_x = cintura.get_rotacao_x() - cintura_s.r_x;
			cintura_s.r_y = cintura.get_rotacao_y() - cintura_s.r_y;
			cintura_s.r_z = cintura.get_rotacao_z() - cintura_s.r_z;

			virilha_d_s.t_x = virilha_d.get_deslocamento_x() - virilha_d_s.t_x;
			virilha_d_s.t_y = virilha_d.get_deslocamento_y() - virilha_d_s.t_y;
			virilha_d_s.t_z = virilha_d.get_deslocamento_z() - virilha_d_s.t_z;
			virilha_d_s.r_x = virilha_d.get_rotacao_x() - virilha_d_s.r_x;
			virilha_d_s.r_y = virilha_d.get_rotacao_y() - virilha_d_s.r_y;
			virilha_d_s.r_z = virilha_d.get_rotacao_z() - virilha_d_s.r_z;

			virilha_e_s.t_x = virilha_e.get_deslocamento_x() - virilha_e_s.t_x;
			virilha_e_s.t_y = virilha_e.get_deslocamento_y() - virilha_e_s.t_y;
			virilha_e_s.t_z = virilha_e.get_deslocamento_z() - virilha_e_s.t_z;
			virilha_e_s.r_x = virilha_e.get_rotacao_x() - virilha_e_s.r_x;
			virilha_e_s.r_y = virilha_e.get_rotacao_y() - virilha_e_s.r_y;
			virilha_e_s.r_z = virilha_e.get_rotacao_z() - virilha_e_s.r_z;

			joelho_d_s.t_x = joelho_d.get_deslocamento_x() - joelho_d_s.t_x;
			joelho_d_s.t_y = joelho_d.get_deslocamento_y() - joelho_d_s.t_y;
			joelho_d_s.t_z = joelho_d.get_deslocamento_z() - joelho_d_s.t_z;
			joelho_d_s.r_x = joelho_d.get_rotacao_x() - joelho_d_s.r_x;
			joelho_d_s.r_y = joelho_d.get_rotacao_y() - joelho_d_s.r_y;
			joelho_d_s.r_z = joelho_d.get_rotacao_z() - joelho_d_s.r_z;

			joelho_e_s.t_x = joelho_e.get_deslocamento_x() - joelho_e_s.t_x;
			joelho_e_s.t_y = joelho_e.get_deslocamento_y() - joelho_e_s.t_y;
			joelho_e_s.t_z = joelho_e.get_deslocamento_z() - joelho_e_s.t_z;
			joelho_e_s.r_x = joelho_e.get_rotacao_x() - joelho_e_s.r_x;
			joelho_e_s.r_y = joelho_e.get_rotacao_y() - joelho_e_s.r_y;
			joelho_e_s.r_z = joelho_e.get_rotacao_z() - joelho_e_s.r_z;

			tornozelo_d_s.t_x = tornozelo_d.get_deslocamento_x() - tornozelo_d_s.t_x;
			tornozelo_d_s.t_y = tornozelo_d.get_deslocamento_y() - tornozelo_d_s.t_y;
			tornozelo_d_s.t_z = tornozelo_d.get_deslocamento_z() - tornozelo_d_s.t_z;
			tornozelo_d_s.r_x = tornozelo_d.get_rotacao_x() - tornozelo_d_s.r_x;
			tornozelo_d_s.r_y = tornozelo_d.get_rotacao_y() - tornozelo_d_s.r_y;
			tornozelo_d_s.r_z = tornozelo_d.get_rotacao_z() - tornozelo_d_s.r_z;

			tornozelo_e_s.t_x = tornozelo_e.get_deslocamento_x() - tornozelo_e_s.t_x;
			tornozelo_e_s.t_y = tornozelo_e.get_deslocamento_y() - tornozelo_e_s.t_y;
			tornozelo_e_s.t_z = tornozelo_e.get_deslocamento_z() - tornozelo_e_s.t_z;
			tornozelo_e_s.r_x = tornozelo_e.get_rotacao_x() - tornozelo_e_s.r_x;
			tornozelo_e_s.r_y = tornozelo_e.get_rotacao_y() - tornozelo_e_s.r_y;
			tornozelo_e_s.r_z = tornozelo_e.get_rotacao_z() - tornozelo_e_s.r_z;

			ponta_pe_d_s.t_x = ponta_pe_d.get_deslocamento_x() - ponta_pe_d_s.t_x;
			ponta_pe_d_s.t_y = ponta_pe_d.get_deslocamento_y() - ponta_pe_d_s.t_y;
			ponta_pe_d_s.t_z = ponta_pe_d.get_deslocamento_z() - ponta_pe_d_s.t_z;
			ponta_pe_d_s.r_x = ponta_pe_d.get_rotacao_x() - ponta_pe_d_s.r_x;
			ponta_pe_d_s.r_y = ponta_pe_d.get_rotacao_y() - ponta_pe_d_s.r_y;
			ponta_pe_d_s.r_z = ponta_pe_d.get_rotacao_z() - ponta_pe_d_s.r_z;

			ponta_pe_e_s.t_x = ponta_pe_e.get_deslocamento_x() - ponta_pe_e_s.t_x;
			ponta_pe_e_s.t_y = ponta_pe_e.get_deslocamento_y() - ponta_pe_e_s.t_y;
			ponta_pe_e_s.t_z = ponta_pe_e.get_deslocamento_z() - ponta_pe_e_s.t_z;
			ponta_pe_e_s.r_x = ponta_pe_e.get_rotacao_x() - ponta_pe_e_s.r_x;
			ponta_pe_e_s.r_y = ponta_pe_e.get_rotacao_y() - ponta_pe_e_s.r_y;
			ponta_pe_e_s.r_z = ponta_pe_e.get_rotacao_z() - ponta_pe_e_s.r_z;

			espinha_d_1_s.t_x = espinha_d_1.get_deslocamento_x() - espinha_d_1_s.t_x;
			espinha_d_1_s.t_y = espinha_d_1.get_deslocamento_y() - espinha_d_1_s.t_y;
			espinha_d_1_s.t_z = espinha_d_1.get_deslocamento_z() - espinha_d_1_s.t_z;
			espinha_d_1_s.r_x = espinha_d_1.get_rotacao_x() - espinha_d_1_s.r_x;
			espinha_d_1_s.r_y = espinha_d_1.get_rotacao_y() - espinha_d_1_s.r_y;
			espinha_d_1_s.r_z = espinha_d_1.get_rotacao_z() - espinha_d_1_s.r_z;

			espinha_d_2_s.t_x = espinha_d_2.get_deslocamento_x() - espinha_d_2_s.t_x;
			espinha_d_2_s.t_y = espinha_d_2.get_deslocamento_y() - espinha_d_2_s.t_y;
			espinha_d_2_s.t_z = espinha_d_2.get_deslocamento_z() - espinha_d_2_s.t_z;
			espinha_d_2_s.r_x = espinha_d_2.get_rotacao_x() - espinha_d_2_s.r_x;
			espinha_d_2_s.r_y = espinha_d_2.get_rotacao_y() - espinha_d_2_s.r_y;
			espinha_d_2_s.r_z = espinha_d_2.get_rotacao_z() - espinha_d_2_s.r_z;

			espinha_d_3_s.t_x = espinha_d_3.get_deslocamento_x() - espinha_d_3_s.t_x;
			espinha_d_3_s.t_y = espinha_d_3.get_deslocamento_y() - espinha_d_3_s.t_y;
			espinha_d_3_s.t_z = espinha_d_3.get_deslocamento_z() - espinha_d_3_s.t_z;
			espinha_d_3_s.r_x = espinha_d_3.get_rotacao_x() - espinha_d_3_s.r_x;
			espinha_d_3_s.r_y = espinha_d_3.get_rotacao_y() - espinha_d_3_s.r_y;
			espinha_d_3_s.r_z = espinha_d_3.get_rotacao_z() - espinha_d_3_s.r_z;

			ombro_d_s.t_x = ombro_d.get_deslocamento_x() - ombro_d_s.t_x;
			ombro_d_s.t_y = ombro_d.get_deslocamento_y() - ombro_d_s.t_y;
			ombro_d_s.t_z = ombro_d.get_deslocamento_z() - ombro_d_s.t_z;
			ombro_d_s.r_x = ombro_d.get_rotacao_x() - ombro_d_s.r_x;
			ombro_d_s.r_y = ombro_d.get_rotacao_y() - ombro_d_s.r_y;
			ombro_d_s.r_z = ombro_d.get_rotacao_z() - ombro_d_s.r_z;

			ombro_e_s.t_x = ombro_e.get_deslocamento_x() - ombro_e_s.t_x;
			ombro_e_s.t_y = ombro_e.get_deslocamento_y() - ombro_e_s.t_y;
			ombro_e_s.t_z = ombro_e.get_deslocamento_z() - ombro_e_s.t_z;
			ombro_e_s.r_x = ombro_e.get_rotacao_x() - ombro_e_s.r_x;
			ombro_e_s.r_y = ombro_e.get_rotacao_y() - ombro_e_s.r_y;
			ombro_e_s.r_z = ombro_e.get_rotacao_z() - ombro_e_s.r_z;

			cotovelo_d_s.t_x = cotovelo_d.get_deslocamento_x() - cotovelo_d_s.t_x;
			cotovelo_d_s.t_y = cotovelo_d.get_deslocamento_y() - cotovelo_d_s.t_y;
			cotovelo_d_s.t_z = cotovelo_d.get_deslocamento_z() - cotovelo_d_s.t_z;
			cotovelo_d_s.r_x = cotovelo_d.get_rotacao_x() - cotovelo_d_s.r_x;
			cotovelo_d_s.r_y = cotovelo_d.get_rotacao_y() - cotovelo_d_s.r_y;
			cotovelo_d_s.r_z = cotovelo_d.get_rotacao_z() - cotovelo_d_s.r_z;

			cotovelo_e_s.t_x = cotovelo_e.get_deslocamento_x() - cotovelo_e_s.t_x;
			cotovelo_e_s.t_y = cotovelo_e.get_deslocamento_y() - cotovelo_e_s.t_y;
			cotovelo_e_s.t_z = cotovelo_e.get_deslocamento_z() - cotovelo_e_s.t_z;
			cotovelo_e_s.r_x = cotovelo_e.get_rotacao_x() - cotovelo_e_s.r_x;
			cotovelo_e_s.r_y = cotovelo_e.get_rotacao_y() - cotovelo_e_s.r_y;
			cotovelo_e_s.r_z = cotovelo_e.get_rotacao_z() - cotovelo_e_s.r_z;

			pulso_d_s.t_x = pulso_d.get_deslocamento_x() - pulso_d_s.t_x;
			pulso_d_s.t_y = pulso_d.get_deslocamento_y() - pulso_d_s.t_y;
			pulso_d_s.t_z = pulso_d.get_deslocamento_z() - pulso_d_s.t_z;
			pulso_d_s.r_x = pulso_d.get_rotacao_x() - pulso_d_s.r_x;
			pulso_d_s.r_y = pulso_d.get_rotacao_y() - pulso_d_s.r_y;
			pulso_d_s.r_z = pulso_d.get_rotacao_z() - pulso_d_s.r_z;

			pulso_e_s.t_x = pulso_e.get_deslocamento_x() - pulso_e_s.t_x;
			pulso_e_s.t_y = pulso_e.get_deslocamento_y() - pulso_e_s.t_y;
			pulso_e_s.t_z = pulso_e.get_deslocamento_z() - pulso_e_s.t_z;
			pulso_e_s.r_x = pulso_e.get_rotacao_x() - pulso_e_s.r_x;
			pulso_e_s.r_y = pulso_e.get_rotacao_y() - pulso_e_s.r_y;
			pulso_e_s.r_z = pulso_e.get_rotacao_z() - pulso_e_s.r_z;

			junta_pescoco_s.t_x = junta_pescoco.get_deslocamento_x() - junta_pescoco_s.t_x;
			junta_pescoco_s.t_y = junta_pescoco.get_deslocamento_y() - junta_pescoco_s.t_y;
			junta_pescoco_s.t_z = junta_pescoco.get_deslocamento_z() - junta_pescoco_s.t_z;
			junta_pescoco_s.r_x = junta_pescoco.get_rotacao_x() - junta_pescoco_s.r_x;
			junta_pescoco_s.r_y = junta_pescoco.get_rotacao_y() - junta_pescoco_s.r_y;
			junta_pescoco_s.r_z = junta_pescoco.get_rotacao_z() - junta_pescoco_s.r_z;


			matriz_s << cintura_s.t_x << " " << cintura_s.t_y << " " << cintura_s.t_z << " " << cintura_s.r_x << " " << cintura_s.r_y << " " << cintura_s.r_z << " ";
			matriz_s << virilha_d_s.t_x << " " << virilha_d_s.t_y << " " << virilha_d_s.t_z << " " << virilha_d_s.r_x << " " << virilha_d_s.r_y << " " << virilha_d_s.r_z << " ";
			matriz_s << virilha_e_s.t_x << " " << virilha_e_s.t_y << " " << virilha_e_s.t_z << " " << virilha_e_s.r_x << " " << virilha_e_s.r_y << " " << virilha_e_s.r_z << " ";
			matriz_s << joelho_d_s.t_x << " " << joelho_d_s.t_y << " " << joelho_d_s.t_z << " " << joelho_d_s.r_x << " " << joelho_d_s.r_y << " " << joelho_d_s.r_z << " ";
			matriz_s << joelho_e_s.t_x << " " << joelho_e_s.t_y << " " << joelho_e_s.t_z << " " << joelho_e_s.r_x << " " << joelho_e_s.r_y << " " << joelho_e_s.r_z << " ";
			matriz_s << tornozelo_d_s.t_x << " " << tornozelo_d_s.t_y << " " << tornozelo_d_s.t_z << " " << tornozelo_d_s.r_x << " " << tornozelo_d_s.r_y << " " << tornozelo_d_s.r_z << " ";
			matriz_s << tornozelo_e_s.t_x << " " << tornozelo_e_s.t_y << " " << tornozelo_e_s.t_z << " " << tornozelo_e_s.r_x << " " << tornozelo_e_s.r_y << " " << tornozelo_e_s.r_z << " ";
			matriz_s << ponta_pe_d_s.t_x << " " << ponta_pe_d_s.t_y << " " << ponta_pe_d_s.t_z << " " << ponta_pe_d_s.r_x << " " << ponta_pe_d_s.r_y << " " << ponta_pe_d_s.r_z << " ";
			matriz_s << ponta_pe_e_s.t_x << " " << ponta_pe_e_s.t_y << " " << ponta_pe_e_s.t_z << " " << ponta_pe_e_s.r_x << " " << ponta_pe_e_s.r_y << " " << ponta_pe_e_s.r_z << " ";
			matriz_s << espinha_d_1_s.t_x << " " << espinha_d_1_s.t_y << " " << espinha_d_1_s.t_z << " " << espinha_d_1_s.r_x << " " << espinha_d_1_s.r_y << " " << espinha_d_1_s.r_z << " ";
			matriz_s << espinha_d_2_s.t_x << " " << espinha_d_2_s.t_y << " " << espinha_d_2_s.t_z << " " << espinha_d_2_s.r_x << " " << espinha_d_2_s.r_y << " " << espinha_d_2_s.r_z << " ";
			matriz_s << espinha_d_3_s.t_x << " " << espinha_d_3_s.t_y << " " << espinha_d_3_s.t_z << " " << espinha_d_3_s.r_x << " " << espinha_d_3_s.r_y << " " << espinha_d_3_s.r_z << " ";
			matriz_s << ombro_d_s.t_x << " " << ombro_d_s.t_y << " " << ombro_d_s.t_z << " " << ombro_d_s.r_x << " " << ombro_d_s.r_y << " " << ombro_d_s.r_z << " ";
			matriz_s << ombro_e_s.t_x << " " << ombro_e_s.t_y << " " << ombro_e_s.t_z << " " << ombro_e_s.r_x << " " << ombro_e_s.r_y << " " << ombro_e_s.r_z << " ";
			matriz_s << cotovelo_d_s.t_x << " " << cotovelo_d_s.t_y << " " << cotovelo_d_s.t_z << " " << cotovelo_d_s.r_x << " " << cotovelo_d_s.r_y << " " << cotovelo_d_s.r_z << " ";
			matriz_s << cotovelo_e_s.t_x << " " << cotovelo_e_s.t_y << " " << cotovelo_e_s.t_z << " " << cotovelo_e_s.r_x << " " << cotovelo_e_s.r_y << " " << cotovelo_e_s.r_z << " ";
			matriz_s << pulso_d_s.t_x << " " << pulso_d_s.t_y << " " << pulso_d_s.t_z << " " << pulso_d_s.r_x << " " << pulso_d_s.r_y << " " << pulso_d_s.r_z << " ";
			matriz_s << pulso_e_s.t_x << " " << pulso_e_s.t_y << " " << pulso_e_s.t_z << " " << pulso_e_s.r_x << " " << pulso_e_s.r_y << " " << pulso_e_s.r_z << " ";
			matriz_s << junta_pescoco_s.t_x << " " << junta_pescoco_s.t_y << " " << junta_pescoco_s.t_z << " " << junta_pescoco_s.r_x << " " << junta_pescoco_s.r_y << " " << junta_pescoco_s.r_z << endl;


			cintura_s.t_x = cintura.get_deslocamento_x();
			cintura_s.t_y = cintura.get_deslocamento_y();
			cintura_s.t_z = cintura.get_deslocamento_z();
			cintura_s.r_x = cintura.get_rotacao_x();
			cintura_s.r_y = cintura.get_rotacao_y();
			cintura_s.r_z = cintura.get_rotacao_z();

			virilha_d_s.t_x = virilha_d.get_deslocamento_x();
			virilha_d_s.t_y = virilha_d.get_deslocamento_y();
			virilha_d_s.t_z = virilha_d.get_deslocamento_z();
			virilha_d_s.r_x = virilha_d.get_rotacao_x();
			virilha_d_s.r_y = virilha_d.get_rotacao_y();
			virilha_d_s.r_z = virilha_d.get_rotacao_z();

			virilha_e_s.t_x = virilha_e.get_deslocamento_x();
			virilha_e_s.t_y = virilha_e.get_deslocamento_y();
			virilha_e_s.t_z = virilha_e.get_deslocamento_z();
			virilha_e_s.r_x = virilha_e.get_rotacao_x();
			virilha_e_s.r_y = virilha_e.get_rotacao_y();
			virilha_e_s.r_z = virilha_e.get_rotacao_z();

			joelho_d_s.t_x = joelho_d.get_deslocamento_x();
			joelho_d_s.t_y = joelho_d.get_deslocamento_y();
			joelho_d_s.t_z = joelho_d.get_deslocamento_z();
			joelho_d_s.r_x = joelho_d.get_rotacao_x();
			joelho_d_s.r_y = joelho_d.get_rotacao_y();
			joelho_d_s.r_z = joelho_d.get_rotacao_z();

			joelho_e_s.t_x = joelho_e.get_deslocamento_x();
			joelho_e_s.t_y = joelho_e.get_deslocamento_y();
			joelho_e_s.t_z = joelho_e.get_deslocamento_z();
			joelho_e_s.r_x = joelho_e.get_rotacao_x();
			joelho_e_s.r_y = joelho_e.get_rotacao_y();
			joelho_e_s.r_z = joelho_e.get_rotacao_z();

			tornozelo_d_s.t_x = tornozelo_d.get_deslocamento_x();
			tornozelo_d_s.t_y = tornozelo_d.get_deslocamento_y();
			tornozelo_d_s.t_z = tornozelo_d.get_deslocamento_z();
			tornozelo_d_s.r_x = tornozelo_d.get_rotacao_x();
			tornozelo_d_s.r_y = tornozelo_d.get_rotacao_y();
			tornozelo_d_s.r_z = tornozelo_d.get_rotacao_z();

			tornozelo_e_s.t_x = tornozelo_e.get_deslocamento_x();
			tornozelo_e_s.t_y = tornozelo_e.get_deslocamento_y();
			tornozelo_e_s.t_z = tornozelo_e.get_deslocamento_z();
			tornozelo_e_s.r_x = tornozelo_e.get_rotacao_x();
			tornozelo_e_s.r_y = tornozelo_e.get_rotacao_y();
			tornozelo_e_s.r_z = tornozelo_e.get_rotacao_z();

			ponta_pe_d_s.t_x = ponta_pe_d.get_deslocamento_x();
			ponta_pe_d_s.t_y = ponta_pe_d.get_deslocamento_y();
			ponta_pe_d_s.t_z = ponta_pe_d.get_deslocamento_z();
			ponta_pe_d_s.r_x = ponta_pe_d.get_rotacao_x();
			ponta_pe_d_s.r_y = ponta_pe_d.get_rotacao_y();
			ponta_pe_d_s.r_z = ponta_pe_d.get_rotacao_z();

			ponta_pe_e_s.t_x = ponta_pe_e.get_deslocamento_x();
			ponta_pe_e_s.t_y = ponta_pe_e.get_deslocamento_y();
			ponta_pe_e_s.t_z = ponta_pe_e.get_deslocamento_z();
			ponta_pe_e_s.r_x = ponta_pe_e.get_rotacao_x();
			ponta_pe_e_s.r_y = ponta_pe_e.get_rotacao_y();
			ponta_pe_e_s.r_z = ponta_pe_e.get_rotacao_z();

			espinha_d_1_s.t_x = espinha_d_1.get_deslocamento_x();
			espinha_d_1_s.t_y = espinha_d_1.get_deslocamento_y();
			espinha_d_1_s.t_z = espinha_d_1.get_deslocamento_z();
			espinha_d_1_s.r_x = espinha_d_1.get_rotacao_x();
			espinha_d_1_s.r_y = espinha_d_1.get_rotacao_y();
			espinha_d_1_s.r_z = espinha_d_1.get_rotacao_z();

			espinha_d_2_s.t_x = espinha_d_2.get_deslocamento_x();
			espinha_d_2_s.t_y = espinha_d_2.get_deslocamento_y();
			espinha_d_2_s.t_z = espinha_d_2.get_deslocamento_z();
			espinha_d_2_s.r_x = espinha_d_2.get_rotacao_x();
			espinha_d_2_s.r_y = espinha_d_2.get_rotacao_y();
			espinha_d_2_s.r_z = espinha_d_2.get_rotacao_z();

			espinha_d_3_s.t_x = espinha_d_3.get_deslocamento_x();
			espinha_d_3_s.t_y = espinha_d_3.get_deslocamento_y();
			espinha_d_3_s.t_z = espinha_d_3.get_deslocamento_z();
			espinha_d_3_s.r_x = espinha_d_3.get_rotacao_x();
			espinha_d_3_s.r_y = espinha_d_3.get_rotacao_y();
			espinha_d_3_s.r_z = espinha_d_3.get_rotacao_z();

			ombro_d_s.t_x = ombro_d.get_deslocamento_x();
			ombro_d_s.t_y = ombro_d.get_deslocamento_y();
			ombro_d_s.t_z = ombro_d.get_deslocamento_z();
			ombro_d_s.r_x = ombro_d.get_rotacao_x();
			ombro_d_s.r_y = ombro_d.get_rotacao_y();
			ombro_d_s.r_z = ombro_d.get_rotacao_z();

			ombro_e_s.t_x = ombro_e.get_deslocamento_x();
			ombro_e_s.t_y = ombro_e.get_deslocamento_y();
			ombro_e_s.t_z = ombro_e.get_deslocamento_z();
			ombro_e_s.r_x = ombro_e.get_rotacao_x();
			ombro_e_s.r_y = ombro_e.get_rotacao_y();
			ombro_e_s.r_z = ombro_e.get_rotacao_z();

			cotovelo_d_s.t_x = cotovelo_d.get_deslocamento_x();
			cotovelo_d_s.t_y = cotovelo_d.get_deslocamento_y();
			cotovelo_d_s.t_z = cotovelo_d.get_deslocamento_z();
			cotovelo_d_s.r_x = cotovelo_d.get_rotacao_x();
			cotovelo_d_s.r_y = cotovelo_d.get_rotacao_y();
			cotovelo_d_s.r_z = cotovelo_d.get_rotacao_z();

			cotovelo_e_s.t_x = cotovelo_e.get_deslocamento_x();
			cotovelo_e_s.t_y = cotovelo_e.get_deslocamento_y();
			cotovelo_e_s.t_z = cotovelo_e.get_deslocamento_z();
			cotovelo_e_s.r_x = cotovelo_e.get_rotacao_x();
			cotovelo_e_s.r_y = cotovelo_e.get_rotacao_y();
			cotovelo_e_s.r_z = cotovelo_e.get_rotacao_z();

			pulso_d_s.t_x = pulso_d.get_deslocamento_x();
			pulso_d_s.t_y = pulso_d.get_deslocamento_y();
			pulso_d_s.t_z = pulso_d.get_deslocamento_z();
			pulso_d_s.r_x = pulso_d.get_rotacao_x();
			pulso_d_s.r_y = pulso_d.get_rotacao_y();
			pulso_d_s.r_z = pulso_d.get_rotacao_z();

			pulso_e_s.t_x = pulso_e.get_deslocamento_x();
			pulso_e_s.t_y = pulso_e.get_deslocamento_y();
			pulso_e_s.t_z = pulso_e.get_deslocamento_z();
			pulso_e_s.r_x = pulso_e.get_rotacao_x();
			pulso_e_s.r_y = pulso_e.get_rotacao_y();
			pulso_e_s.r_z = pulso_e.get_rotacao_z();

			junta_pescoco_s.t_x = junta_pescoco.get_deslocamento_x();
			junta_pescoco_s.t_y = junta_pescoco.get_deslocamento_y();
			junta_pescoco_s.t_z = junta_pescoco.get_deslocamento_z();
			junta_pescoco_s.r_x = junta_pescoco.get_rotacao_x();
			junta_pescoco_s.r_y = junta_pescoco.get_rotacao_y();
			junta_pescoco_s.r_z = junta_pescoco.get_rotacao_z();
		}
	}

	glutPostRedisplay();
}

// Programa Principal
int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640,480);
	glutCreateWindow("Animation Maker");
	glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
	glutMouseFunc(GerenciaMouse);
	//glutSetKeyRepeat(1);
	glutKeyboardFunc(&keyBoardfunc);
	glutSpecialFunc(&keyBoardSpecialfunc);
	glutSpecialUpFunc(&keyBoardSpecialUpfunc);
	Inicializa();
	glutMainLoop();

}

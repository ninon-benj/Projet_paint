#include <Windows.h>
#include <iostream>
#include <vector>
#include "Interface.h"
#include "Stockage.h"
#include<gl/GL.h>
#include<GLUT.H>
using namespace std;


Icone::Icone(point hg, point bd)
{
	this->coin_hg = hg;
	this->coin_bd = bd;
}

Icone::Icone(point hg, point bd, couleur co)
{
	this->coin_hg = hg;
	this->coin_bd = bd;
	this->c = co;
}

Icone::Icone(point hg, point bd, couleur co, int m)
{
	this->coin_hg = hg;
	this->coin_bd = bd;
	this->c = co;
	this->m = m;
}


GLboolean Icone::est_sur(int x, int y)
{	
	int x1 = (this->coin_hg).x;
	int x2= (this->coin_bd).x;
	int y1= (this->coin_hg).y;
	int y2= (this->coin_bd).y;
	if (x1<x && x<x2)
	{
		if (y1 < y && y < y2)
		{
			return  true;
		}
		else 
		{
			return false;
		}
	}
	return false;
}

//creer les icones de diff�rentes couleurs
vector<Icone> create_icons_coul() {
	//Ic�ne rectangle
	//point i_rect_hg;
	//i_rect_hg.x = 10;
	//i_rect_hg.y = 10;
	//point i_rect_bd;
	//i_rect_bd.x = 150;
	//i_rect_bd.y = 150;
	vector<Icone> res;
	couleur rouge;
	point hgr;
	point bdr;
	rouge.r = 1;
	rouge.g = 0;
	rouge.b = 0;
	rouge.a = 0;
	hgr.x = 10;
	hgr.y = 10;
	bdr.x = 50;
	bdr.y = 50;
	Icone r(hgr,bdr,rouge);
	couleur vert;
	point hgv;
	point bdv;
	vert.r = 0;
	vert.g = 1;
	vert.b = 0;
	vert.a = 0;
	hgv.x = 60;
	hgv.y = 10;
	bdv.x = 100;
	bdv.y = 50;
	Icone v(hgv, bdv, vert);
	couleur bleu;
	point hgb;
	point bdb;
	bleu.r = 0;
	bleu.g = 0;
	bleu.b = 1;
	bleu.a = 0;
	hgb.x = 110;
	hgb.y = 10;
	bdb.x = 150;
	bdb.y = 50;
	Icone b(hgb, bdb, bleu);
	res.push_back(r);
	res.push_back(b);
	res.push_back(v);
	return res;
}


	vector<Icone> create_icons_forme() {
		//FOND COULEUR
		couleur fond;
		fond.r = 0;
		fond.g = 0;
		fond.b = 1;
		fond.a = 0;
		vector<Icone> res;
		//CRAYON CLASSIQUE
		point hgcra;
		point bdcra;
		int mcra = 0;
		hgcra.x = 10;
		hgcra.y = 60;
		bdcra.x = 50;
		bdcra.y = 100;
		Icone cra(hgcra, bdcra, fond,mcra);
		//CARRE
		point hgca;
		point bdca;
		int mca = 1;
		hgca.x = 60;
		hgca.y = 60;
		bdca.x = 100;
		bdca.y = 100;
		Icone ca(hgca, bdca, fond,mca);
		//CERCLE
		int mce = 2;
		point hgce;
		point bdce;
		hgce.x = 110;
		hgce.y = 60;
		bdce.x = 150;
		bdce.y = 100;
		Icone ce(hgce, bdce, fond,mce);
		res.push_back(cra);
		res.push_back(ca);
		res.push_back(ce);
		return res;
}


GLvoid draw_colors(vector<Icone> ico) {

	for (Icone& i : ico) {
		couleur c = i.getC();
		point hg = i.getHG();
		point bd = i.getBD();
		glMatrixMode(GL_MODELVIEW);
		glColor4f(c.r, c.g, c.b, c.a);
		glRectf(hg.x, hg.y, bd.x, bd.y);

		glEnd();
	}
}

//GLvoid draw_colors(vector<Icone> ico) {
//
//	for (Icone& i : ico) {
//		couleur c = i.getC();
//		point hg = i.getHG();
//		point bd = i.getBD();
//		glMatrixMode(GL_MODELVIEW);
//		glColor4f(c.r, c.g, c.b, c.a);
//		glRectf(hg.x, hg.y, bd.x, bd.y);
//
//		glEnd();
//	}
//};
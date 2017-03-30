// EX5.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "CImg.h"
#include "noiseRemoval.h"
#include "contourDetect.h"
#include "voting.h"
#include "warping.h"
#include<iostream>
using namespace std;
using namespace cimg_library;

int main() {
	const char* filepath = "Dataset/3.bmp";//�ļ�����
	CImg<double> img(filepath), paint(filepath);//����ͼƬ
	img = RemoveNoise(img);//ģ��
	img = sobel(img); //��Ե���
	voting vote(img);
	//vector<pair<int, int>> line = vote.getLines();
	//int r = vote.getR();
	Warp(img, vote.getLines(), vote.getR(), paint);
}


#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <string>

using namespace std;


struct Img {
	int* srcImg;
	int width;
	int height;

	int x_c;
	int y_c;

	Img();
	Img(int w, int h);
	Img(const int* src, int w, int h);
	~Img();
};

class ImageProcess {
private:
	Img* srcImg;
	Img* processedImg;
	Img* mask;

	void imgOut(Img*& Image);
	int** createMat(int n, int m);
	void deleteMat(int** A);
	void matOut(int** A, int height, int width);
	void putMask(int**& A, int y, int x, int height, int width, int**& Used);
	void checkMask(int** A, int y, int x, int height, int width, int**& Mirror);
	void copyImg(Img*& target, Img* source);
	void copyImg(Img*& target, const Img* source);
	//caanu ii?ii iauyaeyou a?oaea ia?aiaiiua e ooieoee
public:
	//caanu iaeucy iauyaeyou ooieoee e ia?aiaiiua
	/**/
	ImageProcess();
	/* auaaeyaony iaiyou aey ea?oeiee ?acia?a w*h */
	ImageProcess(int w, int h);
	/* auaaeyaony iaiyou aey ea?oeiee ?acia?a w*h e eiie?oaony ea?oeiea*/
	ImageProcess(const Img* img);
	/* auaaeyaony iaiyou aey ea?oeiee eiie?oaony ea?oeiea ec oaeea, ia?aay no?i?ea a oaeea niaa??eo oe?eio e aunioo ea?oeiee*/
	ImageProcess(const char* fileName);
	~ImageProcess();

	/*caaaiea ianee*/
	int updateMask(const Img& mask);
	/*ia?acaienaou enoiaio? ea?oeieo ea?oeieie, eioi?ay auea iieo?aia a ?acoeuoaoa aeeaoaoee e/eee y?icee*/
	int updateSrcImg();
	/*aeeaoaoey ea?oeiee, ?acoeuoao caienaou a processedImg*/
	/*
		input		:	srcImg = 1, ia?aaaouaaaony srcImg  - ?acoeuoao caienuaaaony a processedImg
						srcImg = 0, ia?aaaouaaaony processedImg - ?acoeuoao caienuaaaony a processedImg
	*/
	int dilatation(int srcImg = 1);	//eni?aaeou ia dilatation
	/*y?icey ea?oeiee, ?acoeuoao caienaou a processedImg*/
	int erosion(int srcImg = 1);
	/*
		caa?oceou/nio?aieou ec oaeea n eiaiaii fileName ea?oeieo
		input		:	fileName - eiy oaeea
						format - oi?iao oaeea 	0 - iineaaiaaoaeuiinou 0 e 1, aac ia?aoiaa ia iiao? no?ieo
												1 - iineaaiaaoaeuiinou 0 e 1, n ia?aoiaii ia iiao? no?ieo
	*/
	int loadImgFromFile(const char* fileName, int format = 1);
	int saveImgToFile(const char* fileName, int format = 1);

	/*ia ca??o aac ca??oa*/
	std::list<std::list<std::pair<int /*x*/, int /*y*/>>> getListContours();
};

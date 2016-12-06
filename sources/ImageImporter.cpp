#include "../includes/ImageImporter.h"
#include <iostream>
#include <assert.h>



using namespace std;
namespace maptomix {

ImageImporter* ImageImporter::instance = nullptr;


ImageImporter::ImageImporter():maptomix::Model()
	
{

}

ImageImporter::~ImageImporter(){
	
		SDL_FreeSurface(surf);
}

/*************************************************************************************************************/

ImageImporter* ImageImporter::getInstance(){
	if(instance == nullptr)
		instance = new ImageImporter(); 
	return instance;

}


/**************************************************************************************************************/


void ImageImporter::close(){
	delete instance;

}



/**************************************************************************************************************/


SDL_Surface* ImageImporter::load_image(const char* file){
        surf = IMG_Load(file);
	if(!surf)
		cout<<"Img load problem : " << IMG_GetError()<<endl;
	
	return surf;


}






/**************************************************************************************************************/


void ImageImporter::save_image(SDL_Surface* surface,const char* filename){
	SDL_SaveBMP(surface,filename);


}














}










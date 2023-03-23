#include<stdio.h>

int X0 = 1, X1 = 0, X10 = 1, X11 = 0, X12 = 0, X13 = 0, X14 = 0, X2 = 0, X20 = 1, 
	X21 = 0, X22 = 0, X3 = 0, X30 = 1, X31 = 0, X4 = 0, X40 = 1, X41 = 0, X42 = 0;

void grafcet0();
void datapath0();
void action();
void DataCollection();

void grafcet1();
void datapath1();
void DataAnalysis();

void grafcet2();
void datapath2();
void Control();

void grafcet3();
void datapath3();
void BlynkDisplay();

void grafcet4();
void datapath4();
void Waiting();
void ImageAquisition();
void TempHumiAqui();
void ImageRecognition();
void TempHumiAnal();
void ModeSelect();
void WifiConnect();
void BlyinkDisplay();

void main(){
	printf("X0 = %d,X1 = %d,X2 = %d,X3 = %d,X4 = %d\n",X0 ,X1 ,X2 ,X3 ,X4 );
	while(1){
		datapath0();
		grafcet0();
		printf("X0 = %d,X1 = %d,X2 = %d,X3 = %d,X4 = %d\n",X0 ,X1 ,X2 ,X3 ,X4 );
	}
}

void grafcet0(){

	if((X0 == 1) && (1)){
		X0 = 0;
		X1 = 1;
		return;
	}

	if((X1 == 1) && (Image || Temperature || Humidity)){
		X1 = 0;
		X2 = 1;
		return;
	}

	if((X2 == 1) && (Condition)){
		X2 = 0;
		X3 = 1;
		return;
	}

	if((X3 == 1) && (Connected == true)){
		X3 = 0;
		X4 = 1;
		return;
	}

	if((X4 == 1) && (1)){
		X4 = 0;
		X0 = 1;
		return;
	}

}

void grafcet1(){

	if((X10 == 1) && (R0)){
		X10 = 0;
		X11 = 1;
		return;
	}

	if((X11 == 1) && (Timer == 1000)){
		X11 = 0;
		X12 = 1;
		X13 = 1;
		return;
	}

	if(X12 == 1 && (Image == 1)){
		X12 = 0;
		X14 = 1;
		return;
	}

	if(X13 == 1 && (Temperature && Humidity)){
		X13 = 0;
		X14 = 1;
		return;
	}


	if((X14 == 1) && (1)){
		X14 = 0;
		X10 = 1;
		return;
	}

}

void grafcet2(){

	if(X20 == 1){
		if(Image){
			X20 = 0;
			X21 = 1;
		}
		else if( DHT22){
			X20 = 0;
			X22 = 1;
		}
		return;
	}

	if((X21 == 1) && (1)){
		X21 = 0;
		X20 = 1;
		return;
	}

	if((X22 == 1) && (1)){
		X22 = 0;
		X20 = 1;
		return;
	}

}

void grafcet3(){

	if((X30 == 1) && (1)){
		X30 = 0;
		X31 = 1;
		return;
	}

	if((X31 == 1) && (1)){
		X31 = 0;
		X30 = 1;
		return;
	}

}

void grafcet4(){

	if((X40 == 1) && (1)){
		X40 = 0;
		X41 = 1;
		return;
	}

	if((X41 == 1) && (Connect)){
		X41 = 0;
		X42 = 1;
		return;
	}

	if((X42 == 1) && (DisplaySucess)){
		X42 = 0;
		X40 = 1;
		return;
	}

}

void datapath0(){
	if(X0 == 1)action();
	if(X1 == 1)DataCollection();
	if(X2 == 1)DataAnalysis();
	if(X3 == 1)Control();
	if(X4 == 1)BlynkDisplay();
}

void datapath1(){
if(X10 == 1)action();
if(X11 == 1)Waiting();
if(X12 == 1)ImageAquisition();
if(X13 == 1)TempHumiAqui();
if(X14 == 1)action();
}

void datapath2(){
	if(X20 == 1)action();
	if(X21 == 1)ImageRecognition();
	if(X22 == 1)TempHumiAnal();
}

void datapath3(){
	if(X30 == 1)action();
	if(X31 == 1)ModeSelect();
}

void datapath4(){
	if(X40 == 1)action();
	if(X41 == 1)WifiConnect();
	if(X42 == 1)BlyinkDisplay();
}

void action(){
	printf("action activate !!\n");
}

void DataCollection(){
	printf("DataCollection activate !!\n");
	datapath1();
	grafcet1();
	printf("X10 = %d,X11 = %d,X12 = %d,X13 = %d,X14 = %d\n",X10 ,X11 ,X12 ,X13 ,X14 );
}

void DataAnalysis(){
	printf("DataAnalysis activate !!\n");
	datapath2();
	grafcet2();
	printf("X20 = %d,X21 = %d,X22 = %d\n",X20 ,X21 ,X22 );
}

void Control(){
	printf("Control activate !!\n");
	datapath3();
	grafcet3();
	printf("X30 = %d,X31 = %d\n",X30 ,X31 );
}

void BlynkDisplay(){
	printf("BlynkDisplay activate !!\n");
	datapath4();
	grafcet4();
	printf("X40 = %d,X41 = %d,X42 = %d\n",X40 ,X41 ,X42 );
}

void Waiting(){
	printf("Waiting activate !!\n");
}

void ImageAquisition(){
	printf("ImageAquisition activate !!\n");
}

void TempHumiAqui(){
	printf("TempHumiAqui activate !!\n");
}

void ImageRecognition(){
	printf("ImageRecognition activate !!\n");
}

void TempHumiAnal(){
	printf("TempHumiAnal activate !!\n");
}

void ModeSelect(){
	printf("ModeSelect activate !!\n");
}

void WifiConnect(){
	printf("WifiConnect activate !!\n");
}

void BlyinkDisplay(){
	printf("BlyinkDisplay activate !!\n");
}

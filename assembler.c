#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int AX,BX,CX,DX;
int RAM[256];
int indisler[256];
    

int opController(char token[]){
	int k;
	bool kontrol = false;
    int i=0;
    int sayac = 0;
    
    if(token[i]=='A'||token[i]=='B'||token[i]=='C'||token[i]=='D'){
        i++;
        if(token[i]=='X'){
            printf("\nHatasiz %s",token);
            return 0;
        } else{
            printf("\nhatali %s",token);
            return 0;
        }
    }
    
    else if(token[i] == '['){
    	i++;
    	if(token[i+1] == ']'){
    		for(sayac;sayac<10;sayac++){
    			if(token[i]-'0' == sayac){
    				kontrol = true;
				}
			}
		}else if(token[i+2] == ']'){
			for(sayac=0;sayac<100;sayac++){
    			if((token[i]-'0')*10+(token[i+1]-'0') == sayac){
    				kontrol = true;
				}
			}
		}else if(token[i+3] == ']'){
			for(sayac=0;sayac<256;sayac++){
    			if((token[i]-'0')*100+(token[i+1]-'0')*10+(token[i+2]-'0') == sayac){
    				kontrol = true;
				}
			}
		}else{
			printf("\nhatali %s",token);
			return 0;
		}
			
		if(!kontrol){
			printf("\nhatali %s",token);
			return 0;
		}
		else{
			printf("\nhatasiz %s",token);
			return 0;
		}
	}
    else
    {
    	
    	if(token[i+1]-'0' == -49 || ((int)token[i+1]-48) == -48){
    		for(sayac=0;sayac<10;sayac++){
    			if(token[i]-'0' == sayac){
    				kontrol = true;
				}
			}
		}else if(token[i+2]-'0' == -49 || ((int)token[i+2]-48) == -48){
			for(sayac=10;sayac<100;sayac++){
    			if((token[i]-'0')*10+(token[i+1]-'0') == sayac){
    				kontrol = true;
				}
			}
		}else if(token[i+3]-'0' == -49|| ((int)token[i+3]-48) == -48){
			for(sayac=100;sayac<256;sayac++){
    			if((token[i]-'0')*100+(token[i+1]-'0')*10+(token[i+2]-'0') == sayac){
    				kontrol = true;
				}
			}
    	}else{
			printf("\nhatali %s",token);
			return 0;
		}
		
		if(kontrol){
    		printf("\nhatasiz %s",token);
    		return 0;
		}else{
       		printf("\nhatali %s",token);
       		return 0;
		}
		
	}
	
}
void EtiketController(char token[]){

    int i=0;

    char etiket[] = "ETIKET";
    while (token[i] != '\0'){
        if(etiket[i] == token[i]){
            i++;
            if(token[i+1]=='\0'){
                if(token[i]=='1'||token[i]=='2'||token[i]=='3'||token[i]=='4'||
                token[i]=='5'||token[i]=='6'||token[i]=='7'||token[i]=='8'||token[i]=='9'){
                    printf("\nhatasiz %s",token);
                    break;
                }else
                {
                    printf("\nhatali %s",token);
                    break;
                }
            }
        } else{
            printf("\nhatali %s",token);
            break;
        }
    }
}
int CharCompare(char grammarToken[],char input[]){
    int i=0;
    bool a=true;
    while (input[i] != '\0'){
        if(grammarToken[i]==input[i]){
            i++;
        } else
        {
            a=false;
            break;
        }
    }
    if(a){
        printf("\nhatasiz %s",input);
    } else{
        printf("\nhatali %s",input);
    }
}




int VEY(int i, char array[])
{
	if(array[i] == 'V'){
		if(array[i+4] == 'A'){
			if(array[i+7] == 'A'){
				AX = AX|AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				AX = AX|BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				AX = AX|CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				AX = AX|DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					AX = AX|RAM[(int)array[i+8]-48];
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					AX = AX|RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)];
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					AX = AX|RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)];
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49 || ((int)array[i+8]-48) == -38){
					AX = AX|(int)array[i+7]-48;
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49 || ((int)array[i+9]-48) == -38){
					AX = AX|((int)array[i+7]-48)*10+((int)array[i+8]-48);
					i += 10;
					return i;
				}
				else{
					AX = AX|((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48);
					i += 11;
					return i;
				}
			}
		}
		else if(array[i+4] == 'B'){
			if(array[i+7] == 'A'){
				BX = BX|AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				BX = BX|BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				BX = BX|CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				BX = BX|DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					BX = BX|RAM[(int)array[i+8]-48];
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					BX = BX|RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)];
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					BX = BX|RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)];
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)]=0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49 || ((int)array[i+8]-48) == -38 ){
					BX = BX|(int)array[i+7]-48;
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49 || ((int)array[i+9]-48) == -38 ){
					BX = BX|((int)array[i+7]-48)*10+((int)array[i+8]-48);
					i += 10;
					return i;
				}
				else{
					BX = BX|((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48);
					i += 11;
					return i;
				}
			}
		}
		else if(array[i+4] == 'C'){
			if(array[i+7] == 'A'){
				CX = CX|AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				CX = CX|BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				CX = CX|CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				CX = CX|DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					CX = CX|RAM[(int)array[i+8]-48];
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					CX =  CX|RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)];
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					CX =  CX|RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)];
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49|| ((int)array[i+8]-48) == -38){
					 CX =  CX|(int)array[i+7]-48;
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49|| ((int)array[i+9]-48) == -38){
					 CX =  CX|((int)array[i+7]-48)*10+((int)array[i+8]-48);
					i += 10;
					return i;
				}
				else{
					 CX =  CX|((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48);
					i += 11;
					return i;
				}
			}
		}				
		else if(array[i+4] == 'D'){
			if(array[i+7] == 'A'){
				DX = DX|AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				DX = DX|BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				DX = DX|CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				DX = DX|DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					DX = DX|RAM[(int)array[i+8]-48];
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					DX =  DX|RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)];
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					 DX =  DX|RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)];
					 indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49|| ((int)array[i+8]-48) == -38){
					 DX =  DX|(int)array[i+7]-48;
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49|| ((int)array[i+9]-48) == -38){
					 DX = DX|((int)array[i+7]-48)*10+((int)array[i+8]-48);
					i += 10;
					return i;
				}
				else{
					 DX = DX|((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48);
					i += 11;
					return i;
				}
			}
		}
		else if(array[i+4] == '['){
		 	
			if(array[i+8] == 'A'){
				RAM[(int)array[i+5]-48] |= AX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == 'B'){
				RAM[(int)array[i+5]-48] |= BX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == 'C'){
				RAM[(int)array[i+5]-48] |= CX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == 'D'){
				RAM[(int)array[i+5]-48] |= DX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == '['){
				if(array[i+10] == ']'){
					RAM[(int)array[i+5]-48] |= RAM[(int)array[i+9]-48];
					
					indisler[(int)array[i+5]-48] = 0;
					indisler[(int)array[i+9]-48] = 0;
					
					i += 12;
					return i;
				}
				else if(array[i+11] == ']'){
				    RAM[(int)array[i+5]-48] |= RAM[((int)array[i+9]-48)*10+((int)array[i+10]-48)];
				    
				    indisler[(int)array[i+5]-48] = 0;
				    indisler[((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
				else{
					RAM[(int)array[i+5]-48]  |= RAM[((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48)];
					
					indisler[(int)array[i+5]-48] = 0;
					indisler[((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48)] = 0;
					
					i += 12;
					return i;
				}
			}
			else if(!(array[i+8] == ',') && !(array[i+8] == ']')){
				
				if(((int)array[i+9]-48) == -49 || ((int)array[i+9]-48) == -38 ){
					RAM[(int)array[i+5]-48] |= (int)array[i+8]-48;
					indisler[(int)array[i+5]-48] = 0;
					i += 10;
					return i;
				}
				else if(((int)array[i+10]-48) == -49 || ((int)array[i+10]-48) == -38 ){
					RAM[(int)array[i+5]-48] |= ((int)array[i+8]-48)*10+((int)array[i+9]-48);
					indisler[(int)array[i+5]-48] = 0;
					i += 11;
					return i;
				}
				else{
					RAM[(int)array[i+5]-48] |= ((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48);
					indisler[(int)array[i+5]-48] = 0;
					i += 12;
					return i;
				}
			}
			else if(array[i+9] == 'A'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] |= AX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == 'B'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] |= BX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == 'C'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] |= CX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == 'D'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] |= DX;
				
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == '['){
				if(array[i+11] == ']'){
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] |= RAM[(int)array[i+10]-48];
					
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					indisler[(int)array[i+10]-48] = 0;
					
					i += 13;
					return i;
				}
				else if(array[i+12] == ']'){
				    RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] |= RAM[((int)array[i+10]-48)*10+((int)array[i+11]-48)];
				    
				    indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				    indisler[((int)array[i+10]-48)*10+((int)array[i+11]-48)] = 0;
				    
					i += 14;
					return i;
				}
				else{
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] |= RAM[((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48)];
					
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					indisler[((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48)] = 0;
					
					i += 15;
					return i;
				}
			}
			else if(!(array[i+9]==',')){
						
				if(((int)array[i+10]-48) == -49 || ((int)array[i+10]-48) == -38 ){
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] |= (int)array[i+9]-48;
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					
					i += 11;
					return i;
				}
				else if(((int)array[i+11]-48) == -49 || ((int)array[i+11]-48) == -38 ){
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] |= ((int)array[i+9]-48)*10+((int)array[i+10]-48);
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] |= ((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48);
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else if(array[i+10] == 'A'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] |= AX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == 'B'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] |= BX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				
				i += 13;
				return i;
			}
			else if(array[i+10] == 'C'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] |= CX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == 'D'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] |= DX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == '['){
				if(array[i+12] == ']'){
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] |= RAM[(int)array[i+11]-48];
					
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					indisler[(int)array[i+11]-48] = 0;
					
					i += 14;
					return i;
				}
				else if(array[i+13] == ']'){
				    RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] |= RAM[((int)array[i+11]-48)*10+((int)array[i+12]-48)];
				    
				    indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				    indisler[((int)array[i+11]-48)*10+((int)array[i+12]-48)] = 0;
				    
					i += 15;
					return i;
				}
				else{
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] |= RAM[((int)array[i+11]-48)*100+((int)array[i+12]-48)*10+((int)array[i+13]-48)];
					
					
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					indisler[((int)array[i+11]-48)*100+((int)array[i+12]-48)*10+((int)array[i+13]-48)] = 0;
					
					i += 16;
					return i;
				}
			}
			else if(!(array[i+10]==',')){
						
				if(((int)array[i+11]-48) == -49 || ((int)array[i+11]-48) == -38 ){
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] |= (int)array[i+10]-48;
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					i += 12;
					return i;
				}
				else if(((int)array[i+12]-48) == -49 || ((int)array[i+12]-48) == -38 ){
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] |= ((int)array[i+10]-48)*10+((int)array[i+11]-48);
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					i += 13;
					return i;
				}
				else{
					
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] |= ((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48);
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					i += 14;
					return i;
				}
			}
		}
	}
}



int VE(int i , char array[])
{
	if(array[i] == 'V'){
		if(array[i+3] == 'A'){
			if(array[i+6] == 'A'){
				AX = AX&AX;
				i += 9;
				return i;
			}
			else if(array[i+6] == 'B'){
				AX = AX&BX;
				i += 9;
				return i;
			}
			else if(array[i+6] == 'C'){
				AX = AX&CX;
				i += 9;
				return i;
			}
			else if(array[i+6] == 'D'){
				AX = AX&DX;
				i += 9;
				return i;
			}
			else if(array[i+6] == '['){
				if(array[i+8] == ']'){
					AX = AX&RAM[(int)array[i+7]-48];
					indisler[(int)array[i+7]-48]=0;
					i += 10;
					return i;
				}
				else if(array[i+9] == ']'){
					AX = AX&RAM[((int)array[i+7]-48)*10+((int)array[i+8]-48)];
					indisler[((int)array[i+7]-48)*10+((int)array[i+8]-48)] = 0;
					
					i += 11;
					return i;
				}
				else{
					AX = AX&RAM[((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48)];
					indisler[((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48)]=0;
					i += 12;
					return i;
				}
			}
			else{
						
				if(((int)array[i+7]-48) == -49 || ((int)array[i+7]-48) == -38){
					AX = AX&(int)array[i+6]-48;
					i += 8;
					return i;
				}
				else if(((int)array[i+8]-48) == -49 || ((int)array[i+8]-48) == -38){
					AX = AX&((int)array[i+6]-48)*10+((int)array[i+7]-48);
					i += 9;
					return i;
				}
				else{
					AX = AX&((int)array[i+6]-48)*100+((int)array[i+7]-48)*10+((int)array[i+8]-48);
					i += 10;
					return i;
				}
			}
		}
		else if(array[i+3] == 'B'){
			if(array[i+6] == 'A'){
				BX = BX&AX;
				i += 9;
				return i;
			}
			else if(array[i+6] == 'B'){
				BX = BX&BX;
				i += 9;
				return i;
			}
			else if(array[i+6] == 'C'){
				BX = BX&CX;
				i += 9;
				return i;
			}
			else if(array[i+6] == 'D'){
				BX = BX&DX;
				i += 9;
				return i;
			}
			else if(array[i+6] == '['){
				if(array[i+8] == ']'){
					BX = BX&RAM[(int)array[i+7]-48];
					indisler[(int)array[i+7]-48]=0;
					i += 10;
					return i;
				}
				else if(array[i+9] == ']'){
					BX = BX&RAM[((int)array[i+7]-48)*10+((int)array[i+8]-48)];
					indisler[((int)array[i+7]-48)*10+((int)array[i+8]-48)] = 0;
					i += 11;
					return i;
				}
				else{
					BX = BX&RAM[((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48)];
					indisler[((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					
					i += 12;
					return i;
				}
			}
			else{
						
				if(((int)array[i+7]-48) == -49 || ((int)array[i+7]-48) == -38 ){
					BX = BX&(int)array[i+6]-48;
					i += 8;
					return i;
				}
				else if(((int)array[i+8]-48) == -49 || ((int)array[i+8]-48) == -38 ){
					BX = BX&((int)array[i+6]-48)*10+((int)array[i+7]-48);
					i += 9;
					return i;
				}
				else{
					BX = BX&((int)array[i+6]-48)*100+((int)array[i+7]-48)*10+((int)array[i+8]-48);
					i += 10;
					return i;
				}
			}
		}
		else if(array[i+3] == 'C'){
			if(array[i+6] == 'A'){
				CX = CX&AX;
				i += 9;
				return i;
			}
			else if(array[i+6] == 'B'){
				CX = CX&BX;
				i += 9;
				return i;
			}
			else if(array[i+6] == 'C'){
				CX = CX&CX;
				i += 9;
				return i;
			}
			else if(array[i+6] == 'D'){
				CX = CX&DX;
				i += 9;
				return i;
			}
			else if(array[i+6] == '['){
				if(array[i+8] == ']'){
					CX = CX&RAM[(int)array[i+7]-48];
					indisler[(int)array[i+7]-48] = 0;
					i += 10;
					return i;
				}
				else if(array[i+9] == ']'){
					 CX =  CX&RAM[((int)array[i+7]-48)*10+((int)array[i+8]-48)];
					 indisler[((int)array[i+7]-48)*10+((int)array[i+8]-48)] = 0;
					i += 11;
					return i;
				}
				else{
					CX =  CX&RAM[((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48)];
					indisler[((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
			}
			else{
						
				if(((int)array[i+7]-48) == -49|| ((int)array[i+7]-48) == -38){
					 CX =  CX&(int)array[i+6]-48;
					i += 8;
					return i;
				}
				else if(((int)array[i+8]-48) == -49|| ((int)array[i+8]-48) == -38){
					 CX =  CX&((int)array[i+6]-48)*10+((int)array[i+7]-48);
					i += 9;
					return i;
				}
				else{
					 CX =  CX&((int)array[i+6]-48)*100+((int)array[i+7]-48)*10+((int)array[i+8]-48);
					i += 10;
					return i;
				}
			}
		}		
		else if(array[i+3] == 'D'){
			if(array[i+6] == 'A'){
				DX = DX&AX;
				i += 9;
				return i;
			}
			else if(array[i+6] == 'B'){
				DX = DX&BX;
				i += 9;
				return i;
			}
			else if(array[i+6] == 'C'){
				DX = DX&CX;
				i += 9;
				return i;
			}
			else if(array[i+6] == 'D'){
				DX = DX&DX;
				i += 9;
				return i;
			}
			else if(array[i+6] == '['){
				if(array[i+8] == ']'){
					DX = DX&RAM[(int)array[i+7]-48];
					indisler[(int)array[i+7]-48] = 0;
					
					i += 10;
					return i;
				}
				else if(array[i+9] == ']'){
					DX =  DX&RAM[((int)array[i+7]-48)*10+((int)array[i+8]-48)];
					indisler[((int)array[i+7]-48)*10+((int)array[i+8]-48)] = 0;
					i += 11;
					return i;
				}
				else{
					DX =  DX&RAM[((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48)];
					indisler[((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
			}
			else{
						
				if(((int)array[i+7]-48) == -49|| ((int)array[i+7]-48) == -38){
					 DX =  DX&(int)array[i+6]-48;
					i += 8;
					return i;
				}
				else if(((int)array[i+8]-48) == -49|| ((int)array[i+8]-48) == -38){
					 DX = DX&((int)array[i+6]-48)*10+((int)array[i+7]-48);
					i += 9;
					return i;
				}
				else{
					 DX = DX&((int)array[i+6]-48)*100+((int)array[i+7]-48)*10+((int)array[i+8]-48);
					i += 10;
					return i;
				}
			}
		}
		else if(array[i+3] == '['){
		 	
			if(array[i+7] == 'A'){
				RAM[(int)array[i+4]-48] &= AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				RAM[(int)array[i+4]-48] &= BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				RAM[(int)array[i+4]-48] &= CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				RAM[(int)array[i+4]-48] &= DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					RAM[(int)array[i+4]-48] &= RAM[(int)array[i+8]-48];
					indisler[(int)array[i+4]-48] = 0;
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
				    RAM[(int)array[i+4]-48] &= RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)];
				    indisler[(int)array[i+4]-48] = 0;
				    indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					RAM[(int)array[i+4]-48]  &= RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)];
					
				 	indisler[(int)array[i+4]-48] = 0;	
				 	indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					
					i += 13;
					return i;
				}
			}
			else if(!(array[i+7] == ',') && !(array[i+7] == ']')){
				
				if(((int)array[i+8]-48) == -49 || ((int)array[i+8]-48) == -38 ){
					RAM[(int)array[i+4]-48] &= (int)array[i+7]-48;
					
					indisler[(int)array[i+4]-48] = 0;
					
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49 || ((int)array[i+9]-48) == -38 ){
					RAM[(int)array[i+4]-48] &= ((int)array[i+7]-48)*10+((int)array[i+8]-48);
					indisler[(int)array[i+4]-48] = 0;
					i += 10;
					return i;
				}
				else{
					RAM[(int)array[i+4]-48] &= ((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48);
					indisler[(int)array[i+4]-48] = 0;
					i += 11;
					return i;
				}
			}
		 	else if(array[i+8] == 'A'){
				RAM[((int)array[i+4]-48)*10+((int)array[i+5]-48)] &= AX;
				
				indisler[((int)array[i+4]-48)*10+((int)array[i+5]-48)] = 0;
				
				i += 11;
				return i;
			}
			else if(array[i+8] == 'B'){
				RAM[((int)array[i+4]-48)*10+((int)array[i+5]-48)] &= BX;
				indisler[((int)array[i+4]-48)*10+((int)array[i+5]-48)] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == 'C'){
				RAM[((int)array[i+4]-48)*10+((int)array[i+5]-48)] &= CX;
				indisler[((int)array[i+4]-48)*10+((int)array[i+5]-48)] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == 'D'){
				RAM[((int)array[i+4]-48)*10+((int)array[i+5]-48)] &= DX;
				indisler[((int)array[i+4]-48)*10+((int)array[i+5]-48)] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == '['){
				if(array[i+10] == ']'){
					RAM[((int)array[i+4]-48)*10+((int)array[i+5]-48)] &= RAM[(int)array[i+9]-48];
					indisler[((int)array[i+4]-48)*10+((int)array[i+5]-48)] = 0;
					indisler[(int)array[i+9]-48] = 0;
					
					i += 12;
					return i;
				}
				else if(array[i+11] == ']'){
				    RAM[((int)array[i+4]-48)*10+((int)array[i+5]-48)] &= RAM[((int)array[i+9]-48)*10+((int)array[i+10]-48)];
				    indisler[((int)array[i+4]-48)*10+((int)array[i+5]-48)] = 0;
				    indisler[((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
				    
					i += 13;
					return i;
				}
				else{
					RAM[((int)array[i+4]-48)*10+((int)array[i+5]-48)] &= RAM[((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48)];
					indisler[((int)array[i+4]-48)*10+((int)array[i+5]-48)] = 0;
					indisler[((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48)] = 0;
					i += 14;
					return i;
				}
			}
			else if(!(array[i+8]==',')){
						
				if(((int)array[i+9]-48) == -49 || ((int)array[i+9]-48) == -38 ){
					RAM[((int)array[i+4]-48)*10+((int)array[i+5]-48)] &= (int)array[i+8]-48;
					indisler[((int)array[i+4]-48)*10+((int)array[i+5]-48)] = 0;
					
					i += 10;
					return i;
				}
				else if(((int)array[i+10]-48) == -49 || ((int)array[i+10]-48) == -38 ){
					RAM[((int)array[i+4]-48)*10+((int)array[i+5]-48)] &= ((int)array[i+8]-48)*10+((int)array[i+9]-48);
					indisler[((int)array[i+4]-48)*10+((int)array[i+5]-48)] = 0;
					i += 11;
					return i;
				}
				else{
					RAM[((int)array[i+4]-48)*10+((int)array[i+5]-48)] &= ((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48);
					indisler[((int)array[i+4]-48)*10+((int)array[i+5]-48)] = 0;
					i += 12;
					return i;
				}
			}
			
			
			
			else if(array[i+9] == 'A'){
				RAM[((int)array[i+4]-48)*100+((int)array[i+5]-48)*10+((int)array[i+6]-48)] &= AX;
				indisler[((int)array[i+4]-48)*100+((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == 'B'){
				RAM[((int)array[i+4]-48)*100+((int)array[i+5]-48)*10+((int)array[i+6]-48)] &= BX;
				indisler[((int)array[i+4]-48)*100+((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == 'C'){
				RAM[((int)array[i+4]-48)*100+((int)array[i+5]-48)*10+((int)array[i+6]-48)] &= CX;
				indisler[((int)array[i+4]-48)*100+((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == 'D'){
				RAM[((int)array[i+4]-48)*100+((int)array[i+5]-48)*10+((int)array[i+6]-48)] &= DX;
				indisler[((int)array[i+4]-48)*100+((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == '['){
				if(array[i+11] == ']'){
					RAM[((int)array[i+4]-48)*100+((int)array[i+5]-48)*10+((int)array[i+6]-48)] &= RAM[(int)array[i+10]-48];
					indisler[((int)array[i+4]-48)*100+((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					indisler[(int)array[i+10]-48]=0;
					i += 13;
					return i;
				}
				else if(array[i+12] == ']'){
				    
					RAM[((int)array[i+4]-48)*100+((int)array[i+5]-48)*10+((int)array[i+6]-48)] &= RAM[((int)array[i+10]-48)*10+((int)array[i+11]-48)];
					indisler[((int)array[i+4]-48)*100+((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					indisler[((int)array[i+10]-48)*10+((int)array[i+11]-48)];
					
					i += 14;
					return i;
				}
				else{
					RAM[((int)array[i+4]-48)*100+((int)array[i+5]-48)*10+((int)array[i+6]-48)] &= RAM[((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48)];
					indisler[((int)array[i+4]-48)*100+((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					indisler[((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48)] = 0;
					i += 15;
					return i;
				}
			}
			else if(!(array[i+9]==',')){
						
				if(((int)array[i+10]-48) == -49 || ((int)array[i+10]-48) == -38 ){
					RAM[((int)array[i+4]-48)*100+((int)array[i+5]-48)*10+((int)array[i+6]-48)] &= (int)array[i+9]-48;
					indisler[((int)array[i+4]-48)*100+((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					
					i += 11;
					return i;
				}
				else if(((int)array[i+11]-48) == -49 || ((int)array[i+11]-48) == -38 ){
					RAM[((int)array[i+4]-48)*100+((int)array[i+5]-48)*10+((int)array[i+6]-48)] &= ((int)array[i+9]-48)*10+((int)array[i+10]-48);
					indisler[((int)array[i+4]-48)*100+((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					RAM[((int)array[i+4]-48)*100+((int)array[i+5]-48)*10+((int)array[i+6]-48)] &= ((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48);
					indisler[((int)array[i+4]-48)*100+((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					i += 13;
					return i;
				}
			}
		}
	}
	
}


int ATM(int i , char array[])
{
	if(array[i] == 'A'){
		if(array[i+4] == 'A'){
			if(array[i+7] == 'A'){
				AX = AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				AX = BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				AX = CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				AX = DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					AX = RAM[(int)array[i+8]-48];
					
					indisler[(int)array[i+8]-48]=0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					AX = RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)];
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					AX = RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)];
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
				
				if(((int)array[i+8]-48) == -49 || ((int)array[i+8]-48) == -38){
					AX = (int)array[i+7]-48;
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49 || ((int)array[i+9]-48) == -38){
					AX = ((int)array[i+7]-48)*10+((int)array[i+8]-48);
					i += 10;
					return i;
				}
				else{
					AX = ((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48);
					i += 11;
					return i;
				}
			}
		}
		else if(array[i+4] == 'B'){
			if(array[i+7] == 'A'){
				BX = AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				BX = BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				BX = CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				BX = DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					BX = RAM[(int)array[i+8]-48];
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					BX = RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)];
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					BX = RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)];
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
					
				if(((int)array[i+8]-48) == -49 || ((int)array[i+8]-48) == -38 ){
					BX = (int)array[i+7]-48;
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49 || ((int)array[i+9]-48) == -38 ){
					
					BX = ((int)array[i+7]-48)*10+((int)array[i+8]-48);
					i += 10;
					return i;
				}
				else{
					BX = ((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48);
					i += 11;
					return i;
				}
			}
		}
		else if(array[i+4] == 'C'){
			if(array[i+7] == 'A'){
				CX = AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				CX = BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				CX = CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				CX = DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					CX = RAM[(int)array[i+8]-48];
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					CX = RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)];
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					CX = RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)];
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49|| ((int)array[i+8]-48) == -38){
					 CX =  (int)array[i+7]-48;
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49|| ((int)array[i+9]-48) == -38){
					 CX = ((int)array[i+7]-48)*10+((int)array[i+8]-48);
					i += 10;
					return i;
				}
				else{
					 CX = ((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48);
					i += 11;
					return i;
				}
			}
		}		
		else if(array[i+4] == 'D'){
			if(array[i+7] == 'A'){
				DX = AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				DX = BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				DX = CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				DX = DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					DX = RAM[(int)array[i+8]-48];
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					DX = RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)];
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					DX = RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)];
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49|| ((int)array[i+8]-48) == -38){
					 DX = (int)array[i+7]-48;
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49|| ((int)array[i+9]-48) == -38){
					 DX = ((int)array[i+7]-48)*10+((int)array[i+8]-48);
					i += 10;
					return i;
				}
				else{
					 DX = ((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48);
					i += 11;
					return i;
				}
			}
		 }
		 else if(array[i+4] == '['){
		 	
			if(array[i+8] == 'A'){
				RAM[(int)array[i+5]-48] = AX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == 'B'){
				RAM[(int)array[i+5]-48] = BX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == 'C'){
				RAM[(int)array[i+5]-48] = CX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == 'D'){
				RAM[(int)array[i+5]-48] = DX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == '['){
				if(array[i+10] == ']'){
					RAM[(int)array[i+5]-48] = RAM[(int)array[i+9]-48];
					indisler[(int)array[i+5]-48] = 0;
					indisler[(int)array[i+9]-48] = 0;
					
					i += 12;
					return i;
				}
				else if(array[i+11] == ']'){
				    RAM[(int)array[i+5]-48] = RAM[((int)array[i+9]-48)*10+((int)array[i+10]-48)];
				    indisler[(int)array[i+5]-48] = 0;
				    indisler[((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
				else{
					RAM[(int)array[i+5]-48]  = RAM[((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48)];
					indisler[(int)array[i+5]-48] = 0;
					indisler[((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48)] = 0;
					i += 14;
					return i;
				}
			}
			else if(!(array[i+8] == ',') && !(array[i+8] == ']')){
				
				if(((int)array[i+9]-48) == -49 || ((int)array[i+9]-48) == -38 ){
					RAM[(int)array[i+5]-48] = (int)array[i+8]-48;
					indisler[(int)array[i+5]-48] = 0;
					i += 10;
					return i;
				}
				else if(((int)array[i+10]-48) == -49 || ((int)array[i+10]-48) == -38 ){
					RAM[(int)array[i+5]-48] = ((int)array[i+8]-48)*10+((int)array[i+9]-48);
					indisler[(int)array[i+5]-48] = 0;
					i += 11;
					return i;
				}
				else{
					RAM[(int)array[i+5]-48] = ((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48);
					indisler[(int)array[i+5]-48] = 0;
					i += 12;
					return i;
				}
			}
		 	else if(array[i+9] == 'A'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = AX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == 'B'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = BX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == 'C'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = CX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == 'D'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = DX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == '['){
				if(array[i+11] == ']'){
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = RAM[(int)array[i+10]-48];
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					indisler[(int)array[i+10]-48] = 0;					
					i += 13;
					return i;
				}
				else if(array[i+12] == ']'){
				    RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = RAM[((int)array[i+10]-48)*10+((int)array[i+11]-48)];
				    indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				    indisler[((int)array[i+10]-48)*10+((int)array[i+11]-48)] = 0;
					i += 14;
					return i;
				}
				else{
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = RAM[((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48)];
					
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					indisler[((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48)] = 0;
					
					i += 15;
					return i;
				}
			}
			else if(!(array[i+9]==',')){
						
				if(((int)array[i+10]-48) == -49 || ((int)array[i+10]-48) == -38 ){
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = (int)array[i+9]-48;
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					i += 11;
					return i;
				}
				else if(((int)array[i+11]-48) == -49 || ((int)array[i+11]-48) == -38 ){
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = ((int)array[i+9]-48)*10+((int)array[i+10]-48);
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = ((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48);
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else if(array[i+10] == 'A'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = AX;
				
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == 'B'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = BX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == 'C'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = CX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == 'D'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = DX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == '['){
				if(array[i+12] == ']'){
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = RAM[(int)array[i+11]-48];
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					indisler[(int)array[i+11]-48] = 0;
					i += 14;
					return i;
				}
				else if(array[i+13] == ']'){
				    RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = RAM[((int)array[i+11]-48)*10+((int)array[i+12]-48)];
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					indisler[((int)array[i+11]-48)*10+((int)array[i+12]-48)] = 0;
					i += 15;
					return i;
				}
				else{
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = RAM[((int)array[i+11]-48)*100+((int)array[i+12]-48)*10+((int)array[i+13]-48)];
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					indisler[((int)array[i+11]-48)*100+((int)array[i+12]-48)*10+((int)array[i+13]-48)] = 0;
					i += 16;
					return i;
				}
			}
			else if(!(array[i+10]==',')){
						
				if(((int)array[i+11]-48) == -49 || ((int)array[i+11]-48) == -38 ){
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = (int)array[i+10]-48;
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					
					i += 12;
					return i;
				}
				else if(((int)array[i+12]-48) == -49 || ((int)array[i+12]-48) == -38 ){
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = ((int)array[i+10]-48)*10+((int)array[i+11]-48);
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					i += 13;
					return i;
				}
				else{
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = ((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48);
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					i += 14;
					return i;
				}
			}
		}
	}
}

int TOP(int i , char array[])
{
	
	if(array[i] == 'T'){
		if(array[i+4] == 'A'){
			if(array[i+7] == 'A'){
				AX = AX+AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				AX = AX+BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				AX = AX+CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				AX = AX+DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					AX = AX+RAM[(int)array[i+8]-48];
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					AX = AX+RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)];
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					AX = AX+RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)];
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49 || ((int)array[i+8]-48) == -38){
					AX = AX+(int)array[i+7]-48;
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49 || ((int)array[i+9]-48) == -38){
					AX = AX+((int)array[i+7]-48)*10+((int)array[i+8]-48);
					i += 10;
					return i;
				}
				else{
					AX = AX+((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48);
					i += 11;
					return i;
				}
			}
		}
		else if(array[i+4] == 'B'){
			if(array[i+7] == 'A'){
				BX = BX+AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				BX = BX+BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				BX = BX+CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				BX = BX+DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					BX = BX+RAM[(int)array[i+8]-48];
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					BX = BX+RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)];
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					BX = BX+RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)];
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49 || ((int)array[i+8]-48) == -38 ){
					BX = BX+(int)array[i+7]-48;
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49 || ((int)array[i+9]-48) == -38 ){
					BX = BX+((int)array[i+7]-48)*10+((int)array[i+8]-48);
					i += 10;
					return i;
				}
				else{
					BX = BX+((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48);
					i += 11;
					return i;
				}
			}
		}
		else if(array[i+4] == 'C'){
			if(array[i+7] == 'A'){
				CX = CX+AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				CX = CX+BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				CX = CX+CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				CX = CX+DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					CX = CX+RAM[(int)array[i+8]-48];
					indisler[(int)array[i+8]-48] = 0;
					
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					CX =  CX+RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)];
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					CX =  CX+RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)];
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49|| ((int)array[i+8]-48) == -38){
					 CX =  CX+(int)array[i+7]-48;
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49|| ((int)array[i+9]-48) == -38){
					 CX =  CX+((int)array[i+7]-48)*10+((int)array[i+8]-48);
					i += 10;
					return i;
				}
				else{
					 CX =  CX+((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48);
					i += 11;
					return i;
				}
			}
		}		
		else if(array[i+4] == 'D'){
			if(array[i+7] == 'A'){
				DX = DX+AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				DX = DX+BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				DX = DX+CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				DX = DX+DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					DX = DX+RAM[(int)array[i+8]-48];
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					 DX =  DX+RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)];
					 indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					 DX =  DX+RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)];
					 indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49|| ((int)array[i+8]-48) == -38){
					 DX =  DX+(int)array[i+7]-48;
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49|| ((int)array[i+9]-48) == -38){
					 DX = DX+((int)array[i+7]-48)*10+((int)array[i+8]-48);
					i += 10;
					return i;
				}
				else{
					 DX = DX+((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48);
					i += 11;
					return i;
				}
			}
		}
		else if(array[i+4] == '['){
		 	
			if(array[i+8] == 'A'){
				RAM[(int)array[i+5]-48] += AX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == 'B'){
				RAM[(int)array[i+5]-48] += BX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == 'C'){
				RAM[(int)array[i+5]-48] += CX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == 'D'){
				RAM[(int)array[i+5]-48] += DX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == '['){
				if(array[i+10] == ']'){
					RAM[(int)array[i+5]-48] += RAM[(int)array[i+9]-48];
					indisler[(int)array[i+5]-48] = 0;
					indisler[(int)array[i+9]-48] = 0;
					
					i += 12;
					return i;
				}
				else if(array[i+11] == ']'){
				    RAM[(int)array[i+5]-48] += RAM[((int)array[i+9]-48)*10+((int)array[i+10]-48)];
				    
				    indisler[(int)array[i+5]-48] = 0;
				    indisler[((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
				    
					i += 13;
					return i;
				}
				else{
					RAM[(int)array[i+5]-48]  += RAM[((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48)];
					indisler[(int)array[i+5]-48] = 0;
					indisler[((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48)] = 0;
					i += 12;
					return i;
				}
			}
			else if(!(array[i+8] == ',') && !(array[i+8] == ']')){
				
				if(((int)array[i+9]-48) == -49 || ((int)array[i+9]-48) == -38 ){
					RAM[(int)array[i+5]-48] += (int)array[i+8]-48;
					
					indisler[(int)array[i+5]-48] = 0;
					i += 10;
					return i;
				}
				else if(((int)array[i+10]-48) == -49 || ((int)array[i+10]-48) == -38 ){
					RAM[(int)array[i+5]-48] += ((int)array[i+8]-48)*10+((int)array[i+9]-48);
					indisler[(int)array[i+5]-48] = 0;
					i += 11;
					return i;
				}
				else{
					RAM[(int)array[i+5]-48] += ((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48);
					indisler[(int)array[i+5]-48] = 0;
					i += 12;
					return i;
				}
			}
		 	else if(array[i+9] == 'A'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] += AX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0; 
				i += 12;
				return i;
			}
			else if(array[i+9] == 'B'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] += BX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0; 
				i += 12;
				return i;
			}
			else if(array[i+9] == 'C'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] += CX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0; 
				i += 12;
				return i;
			}
			else if(array[i+9] == 'D'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] += DX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0; 
				i += 12;
				return i;
			}
			else if(array[i+9] == '['){
				if(array[i+11] == ']'){
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] += RAM[(int)array[i+10]-48];
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0; 
					indisler[(int)array[i+10]-48] = 0;
					i += 13;
					return i;
				}
				else if(array[i+12] == ']'){
				    RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] += RAM[((int)array[i+10]-48)*10+((int)array[i+11]-48)];
				    indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0; 
				    indisler[((int)array[i+10]-48)*10+((int)array[i+11]-48)] = 0;
					i += 14;
					return i;
				}
				else{
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] += RAM[((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48)];
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0; 
					indisler[((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48)] = 0;
					i += 15;
					return i;
				}
			}
			else if(!(array[i+9]==',')){
						
				if(((int)array[i+10]-48) == -49 || ((int)array[i+10]-48) == -38 ){
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] += (int)array[i+9]-48;
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					i += 11;
					return i;
				}
				else if(((int)array[i+11]-48) == -49 || ((int)array[i+11]-48) == -38 ){
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] += ((int)array[i+9]-48)*10+((int)array[i+10]-48);
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] += ((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48);
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else if(array[i+10] == 'A'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] += AX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == 'B'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] += BX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == 'C'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] += CX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == 'D'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] += DX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == '['){
				if(array[i+12] == ']'){
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] += RAM[(int)array[i+11]-48];
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					indisler[(int)array[i+11]-48] = 0;
					i += 14;
					return i;
				}
				else if(array[i+13] == ']'){
				    RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] += RAM[((int)array[i+11]-48)*10+((int)array[i+12]-48)];
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					indisler[((int)array[i+11]-48)*10+((int)array[i+12]-48)] = 0;
					
					i += 15;
					return i;
				}
				else{
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] += RAM[((int)array[i+11]-48)*100+((int)array[i+12]-48)*10+((int)array[i+13]-48)];
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					indisler[((int)array[i+11]-48)*100+((int)array[i+12]-48)*10+((int)array[i+13]-48)] = 0;
					
					i += 16;
					return i;
				}
			}
			else if(!(array[i+10]==',')){
						
				if(((int)array[i+11]-48) == -49 || ((int)array[i+11]-48) == -38 ){
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] += (int)array[i+10]-48;
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					
					i += 12;
					return i;
				}
				else if(((int)array[i+12]-48) == -49 || ((int)array[i+12]-48) == -38 ){
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] += ((int)array[i+10]-48)*10+((int)array[i+11]-48);
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					i += 13;
					return i;
				}
				else{
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] += ((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48);
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					i += 14;
					return i;
				}
			}
		}
	}
}


int CIK(int i ,char array[])
{
	
	if(array[i] == 'C'){
		if(array[i+4] == 'A'){
			if(array[i+7] == 'A'){
				AX = AX-AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				AX = AX-BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				AX = AX-CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				AX = AX-DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					AX = AX-(RAM[(int)array[i+8]-48]);
					
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					AX = AX-(RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)]);
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					AX = AX-(RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)]);
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49|| ((int)array[i+8]-48) == -38){
					AX = AX-((int)array[i+7]-48);
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49|| ((int)array[i+9]-48) == -38){
					AX = AX-(((int)array[i+7]-48)*10+((int)array[i+8]-48));
					i += 10;
					return i;
				}
				else{
					AX = AX-(((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48));
					i += 11;
					return i;
				}
			}
		}	
		else if(array[i+4] == 'B'){
			if(array[i+7] == 'A'){
				BX = BX-AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				BX = BX-BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				BX = BX-CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				BX = BX-DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					BX = BX-(RAM[(int)array[i+8]-48]);
					indisler[(int)array[i+8]-48] = 0;
					
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					BX = BX-(RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)]);
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					BX = BX-(RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)]);
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49|| ((int)array[i+8]-48) == -38){
					BX = BX-((int)array[i+7]-48);
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49|| ((int)array[i+9]-48) == -38){
					BX = BX-(((int)array[i+7]-48)*10+((int)array[i+8]-48));
					i += 10;
					return i;
				}
				else{
					BX = BX-(((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48));
					i += 11;
					return i;
				}
			}
		}
		else if(array[i+4] == 'C'){
			if(array[i+7] == 'A'){
				CX = CX-AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				CX = CX-BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				CX = CX-CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				CX = CX-DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					CX = CX-(RAM[(int)array[i+8]-48]);
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					CX = CX-(RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)]);
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					CX = CX-(RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)]);
					
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49|| ((int)array[i+8]-48) == -38){
					CX = CX-((int)array[i+7]-48);
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49|| ((int)array[i+9]-48) == -38){
					CX = CX-(((int)array[i+7]-48)*10+((int)array[i+8]-48));
					i += 10;
					return i;
				}
				else{
					CX = CX-(((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48));
					i += 11;
					return i;
				}
			}
		}		
		else if(array[i+4] == 'D'){
			if(array[i+7] == 'A'){
				DX = DX-AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				DX = DX-BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				DX = DX-CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				DX = DX-DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					DX = DX-(RAM[(int)array[i+8]-48]);
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					DX = DX-(RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)]);
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					DX = DX-(RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)]);
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49|| ((int)array[i+8]-48) == -38){
					DX = DX-((int)array[i+7]-48);
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49|| ((int)array[i+9]-48) == -38){
					DX = DX-(((int)array[i+7]-48)*10+((int)array[i+8]-48));
					i += 10;
					return i;
				}
				else{
					DX = DX-(((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48));
					i += 11;
					return i;
				}
			}
		}
		else if(array[i+4] == '['){
		 	
			if(array[i+8] == 'A'){
				RAM[(int)array[i+5]-48] -= AX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == 'B'){
				RAM[(int)array[i+5]-48] -= BX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == 'C'){
				RAM[(int)array[i+5]-48] -= CX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == 'D'){
				RAM[(int)array[i+5]-48] -= DX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == '['){
				if(array[i+10] == ']'){
					RAM[(int)array[i+5]-48] -= RAM[(int)array[i+9]-48];
					indisler[(int)array[i+5]-48] = 0;
					indisler[(int)array[i+9]-48] = 0;
					i += 12;
					return i;
				}
				else if(array[i+11] == ']'){
				    RAM[(int)array[i+5]-48] -= RAM[((int)array[i+9]-48)*10+((int)array[i+10]-48)];
					indisler[(int)array[i+5]-48] = 0;
					indisler[((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
				else{
					RAM[(int)array[i+5]-48]  -= RAM[((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48)];
					indisler[(int)array[i+5]-48] = 0;
					indisler[((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48)] = 0;
					i += 12;
					return i;
				}
			}
			else if(!(array[i+8] == ',') && !(array[i+8] == ']')){
				
				if(((int)array[i+9]-48) == -49 || ((int)array[i+9]-48) == -38 ){
					RAM[(int)array[i+5]-48] -= (int)array[i+8]-48;
					indisler[(int)array[i+5]-48] = 0;
					i += 10;
					return i;
				}
				else if(((int)array[i+10]-48) == -49 || ((int)array[i+10]-48) == -38 ){
					RAM[(int)array[i+5]-48] -= ((int)array[i+8]-48)*10+((int)array[i+9]-48);
					indisler[(int)array[i+5]-48] = 0;
					i += 11;
					return i;
				}
				else{
					RAM[(int)array[i+5]-48] -= ((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48);
					indisler[(int)array[i+5]-48] = 0;
					i += 12;
					return i;
				}
			}
		 	else if(array[i+9] == 'A'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] -= AX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == 'B'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] -= BX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == 'C'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] -= CX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == 'D'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] -= DX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == '['){
				if(array[i+11] == ']'){
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] -= RAM[(int)array[i+10]-48];
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					indisler[(int)array[i+10]-48] = 0;
					i += 13;
					return i;
				}
				else if(array[i+12] == ']'){
				    RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] -= RAM[((int)array[i+10]-48)*10+((int)array[i+11]-48)];
				    indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				    indisler[((int)array[i+10]-48)*10+((int)array[i+11]-48)] = 0;
					i += 14;
					return i;
				}
				else{
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] -= RAM[((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48)];
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					indisler[((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48)] = 0;
					i += 15;
					return i;
				}
			}
			else if(!(array[i+9]==',')){
						
				if(((int)array[i+10]-48) == -49 || ((int)array[i+10]-48) == -38 ){
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] -= (int)array[i+9]-48;
					
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					
					i += 11;
					return i;
				}
				else if(((int)array[i+11]-48) == -49 || ((int)array[i+11]-48) == -38 ){
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] -= ((int)array[i+9]-48)*10+((int)array[i+10]-48);
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] -= ((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48);
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					i += 13;
					return i;
				}
			}
			
			
			
			else if(array[i+10] == 'A'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] -= AX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == 'B'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] -= BX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == 'C'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] -= CX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == 'D'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] -= DX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == '['){
				if(array[i+12] == ']'){
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] -= RAM[(int)array[i+11]-48];
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					indisler[(int)array[i+11]-48] = 0;
					i += 14;
					return i;
				}
				else if(array[i+13] == ']'){
				    RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] -= RAM[((int)array[i+11]-48)*10+((int)array[i+12]-48)];
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					indisler[((int)array[i+11]-48)*10+((int)array[i+12]-48)] = 0;
					i += 15;
					return i;
				}
				else{
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] -= RAM[((int)array[i+11]-48)*100+((int)array[i+12]-48)*10+((int)array[i+13]-48)];
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					indisler[((int)array[i+11]-48)*100+((int)array[i+12]-48)*10+((int)array[i+13]-48)] = 0;
					i += 16;
					return i;
				}
			}
			else if(!(array[i+10]==',')){
						
				if(((int)array[i+11]-48) == -49 || ((int)array[i+11]-48) == -38 ){
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] -= (int)array[i+10]-48;
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					i += 12;
					return i;
				}
				else if(((int)array[i+12]-48) == -49 || ((int)array[i+12]-48) == -38 ){
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] -= ((int)array[i+10]-48)*10+((int)array[i+11]-48);
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					i += 13;
					return i;
				}
				else{
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] -= ((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48);
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					i += 14;
					return i;
				}
			}
				
		}
	}
}

int CRP(int i , char array[])
{
	if(array[i] == 'C'){
		if(array[i+4] == 'A'){
			if(array[i+7] == 'A'){
				AX = AX*AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				AX = AX*BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				AX = AX*CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				AX = AX*DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					AX = AX*(RAM[(int)array[i+8]-48]);
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					AX = AX*(RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)]);
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					AX = AX*(RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)]);
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49|| ((int)array[i+8]-48) == -38){
					AX = AX*((int)array[i+7]-48);
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49|| ((int)array[i+9]-48) == -38){
					AX = AX*(((int)array[i+7]-48)*10+((int)array[i+8]-48));
					i += 10;
					return i;
				}
				else{
					AX = AX*(((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48));
					i += 11;
					return i;
				}
			}
		}	
		else if(array[i+4] == 'B'){
			if(array[i+7] == 'A'){
				BX = BX*AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				BX = BX*BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				BX = BX*CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				BX = BX*DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					BX = BX*(RAM[(int)array[i+8]-48]);
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					BX = BX*(RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)]);
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					BX = BX*(RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)]);
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49|| ((int)array[i+8]-48) == -38){
					BX = BX*((int)array[i+7]-48);
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49|| ((int)array[i+9]-48) == -38){
					BX = BX*(((int)array[i+7]-48)*10+((int)array[i+8]-48));
					i += 10;
					return i;
				}
				else{
					BX = BX*(((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48));
					i += 11;
					return i;
				}
			}
		}
		else if(array[i+4] == 'C'){
			if(array[i+7] == 'A'){
				CX = CX*AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				CX = CX*BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				CX = CX*CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				CX = CX*DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					CX = CX*(RAM[(int)array[i+8]-48]);
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					CX = CX*(RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)]);
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					CX = CX*(RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)]);
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49|| ((int)array[i+8]-48) == -38){
					CX = CX*((int)array[i+7]-48);
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49|| ((int)array[i+9]-48) == -38){
					CX = CX*(((int)array[i+7]-48)*10+((int)array[i+8]-48));
					i += 10;
					return i;
				}
				else{
					CX = CX*(((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48));
					i += 11;
					return i;
				}
			}
		}		
		else if(array[i+4] == 'D'){
			if(array[i+7] == 'A'){
				DX = DX*AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				DX = DX*BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				DX = DX*CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				DX = DX*DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					DX = DX*(RAM[(int)array[i+8]-48]);
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					DX = DX*(RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)]);
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					DX = DX*(RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)]);
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49|| ((int)array[i+8]-48) == -38){
					DX = DX*((int)array[i+7]-48);
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49|| ((int)array[i+9]-48) == -38){
					DX = DX*(((int)array[i+7]-48)*10+((int)array[i+8]-48));
					i += 10;
					return i;
				}
				else{
					DX = DX*(((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48));
					i += 11;
					return i;
				}
			}
		}
		else if(array[i+4] == '['){
		 	
			if(array[i+8] == 'A'){
				RAM[(int)array[i+5]-48] *= AX;
				indisler[(int)array[i+5]-48] = 0;
				
				i += 11;
				return i;
			}
			else if(array[i+8] == 'B'){
				RAM[(int)array[i+5]-48] *= BX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == 'C'){
				RAM[(int)array[i+5]-48] *= CX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == 'D'){
				RAM[(int)array[i+5]-48] *= DX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == '['){
				if(array[i+10] == ']'){
					RAM[(int)array[i+5]-48] *= RAM[(int)array[i+9]-48];
					indisler[(int)array[i+5]-48] = 0;
					indisler[(int)array[i+9]-48]=0;
					i += 12;
					return i;
				}
				else if(array[i+11] == ']'){
				    RAM[(int)array[i+5]-48] *= RAM[((int)array[i+9]-48)*10+((int)array[i+10]-48)];
				    indisler[(int)array[i+5]-48] = 0;
				    indisler[((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
				else{
					RAM[(int)array[i+5]-48]  *= RAM[((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48)];
					indisler[(int)array[i+5]-48] = 0;
					indisler[((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48)] = 0;
					i += 12;
					return i;
				}
			}
			else if(!(array[i+8] == ',') && !(array[i+8] == ']')){
				
				if(((int)array[i+9]-48) == -49 || ((int)array[i+9]-48) == -38 ){
					RAM[(int)array[i+5]-48] *= (int)array[i+8]-48;
					indisler[(int)array[i+5]-48] = 0;
					
					i += 10;
					return i;
				}
				else if(((int)array[i+10]-48) == -49 || ((int)array[i+10]-48) == -38 ){
					RAM[(int)array[i+5]-48] *= ((int)array[i+8]-48)*10+((int)array[i+9]-48);
					indisler[(int)array[i+5]-48] = 0;
					i += 11;
					return i;
				}
				else{
					RAM[(int)array[i+5]-48] *= ((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48);
					indisler[(int)array[i+5]-48] = 0;
					i += 12;
					return i;
				}
			}
			else if(array[i+9] == 'A'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] *= AX;
				
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == 'B'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] *= BX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == 'C'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] *= CX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == 'D'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] *= DX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == '['){
				if(array[i+11] == ']'){
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] *= RAM[(int)array[i+10]-48];
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					indisler[(int)array[i+10]-48] = 0;
					i += 13;
					return i;
				}
				else if(array[i+12] == ']'){
				    RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] *= RAM[((int)array[i+10]-48)*10+((int)array[i+11]-48)];
				    indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				    indisler[((int)array[i+10]-48)*10+((int)array[i+11]-48)] = 0;
					i += 14;
					return i;
				}
				else{
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] *= RAM[((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48)];
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					indisler[((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48)] = 0;
					i += 15;
					return i;
				}
			}
			else if(!(array[i+9]==',')){
						
				if(((int)array[i+10]-48) == -49 || ((int)array[i+10]-48) == -38 ){
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] *= (int)array[i+9]-48;
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					i += 11;
					return i;
				}
				else if(((int)array[i+11]-48) == -49 || ((int)array[i+11]-48) == -38 ){
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] *= ((int)array[i+9]-48)*10+((int)array[i+10]-48);
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] *= ((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48);
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else if(array[i+10] == 'A'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] *= AX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == 'B'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] *= BX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == 'C'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] *= CX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == 'D'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] *= DX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == '['){
				if(array[i+12] == ']'){
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] *= RAM[(int)array[i+11]-48];
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					indisler[(int)array[i+11]-48] = 0;
					i += 14;
					return i;
				}
				else if(array[i+13] == ']'){
				    RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] *= RAM[((int)array[i+11]-48)*10+((int)array[i+12]-48)];
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					indisler[((int)array[i+11]-48)*10+((int)array[i+12]-48)] = 0;
					i += 15;
					return i;
				}
				else{
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] *= RAM[((int)array[i+11]-48)*100+((int)array[i+12]-48)*10+((int)array[i+13]-48)];
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					indisler[((int)array[i+11]-48)*100+((int)array[i+12]-48)*10+((int)array[i+13]-48)] = 0;
					i += 16;
					return i;
				}
			}
			else if(!(array[i+10]==',')){
						
				if(((int)array[i+11]-48) == -49 || ((int)array[i+11]-48) == -38 ){
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] *= (int)array[i+10]-48;
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					i += 12;
					return i;
				}
				else if(((int)array[i+12]-48) == -49 || ((int)array[i+12]-48) == -38 ){
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] *= ((int)array[i+10]-48)*10+((int)array[i+11]-48);
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					i += 13;
					return i;
				}
				else{
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] *= ((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48);
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					i += 14;
					return i;
				}
			}
		}
	}
}


int BOL(int i , char array[])
{
	if(array[i] == 'B'){
		if(array[i+4] == 'A'){
			if(array[i+7] == 'A'){
				AX = AX/AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				AX = AX/BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				AX = AX/CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				AX = AX/DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					if(RAM[(int)array[i+8]-48]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					AX = AX/(RAM[(int)array[i+8]-48]);
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					if(RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					AX = AX/(RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)]);
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					if(RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					AX = AX/(RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)]);
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49|| ((int)array[i+8]-48) == -38){
					
					if(((int)array[i+7]-48)==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					AX = AX/((int)array[i+7]-48);
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49|| ((int)array[i+9]-48) == -38){
					
					
					AX = AX/(((int)array[i+7]-48)*10+((int)array[i+8]-48));
					i += 10;
					return i;
				}
				else{
				
					AX = AX/(((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48));
					i += 11;
					return i;
				}
			}
		}	
		else if(array[i+4] == 'B'){
			if(array[i+7] == 'A'){
				BX = BX/AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				BX = BX/BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				BX = BX/CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				BX = BX/DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					if(RAM[(int)array[i+8]-48]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					BX = BX/(RAM[(int)array[i+8]-48]);
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					if(RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					BX = BX/(RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)]);
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					
					i += 12;
					return i;
				}
				else{
					if(RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					
					BX = BX/(RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)]);
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49|| ((int)array[i+8]-48) == -38){
					
					if(((int)array[i+7]-48)==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					
					BX = BX/((int)array[i+7]-48);
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49|| ((int)array[i+9]-48) == -38){
					
					
					BX = BX/(((int)array[i+7]-48)*10+((int)array[i+8]-48));
					i += 10;
					return i;
				}
				else{
					
					BX = BX/(((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48));
					i += 11;
					return i;
				}
			}
		}
		else if(array[i+4] == 'C'){
			if(array[i+7] == 'A'){
				CX = CX/AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				CX = CX/BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				CX = CX/CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				CX = CX/DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					if(RAM[(int)array[i+8]-48]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					CX = CX/(RAM[(int)array[i+8]-48]);
					indisler[(int)array[i+8]-48] = 0;
					
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					if(RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					CX = CX/(RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)]);
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					if(RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					CX = CX/(RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)]);
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49|| ((int)array[i+8]-48) == -38){
					
					if(((int)array[i+7]-48)==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					CX = CX/((int)array[i+7]-48);
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49|| ((int)array[i+9]-48) == -38){
					
					
					CX = CX/(((int)array[i+7]-48)*10+((int)array[i+8]-48));
					i += 10;
					return i;
				}
				else{
				
				
					CX = CX/(((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48));
					i += 11;
					return i;
				}
			}
		}		
		else if(array[i+4] == 'D'){
			if(array[i+7] == 'A'){
				DX = DX/AX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'B'){
				DX = DX/BX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'C'){
				DX = DX/CX;
				i += 10;
				return i;
			}
			else if(array[i+7] == 'D'){
				DX = DX/DX;
				i += 10;
				return i;
			}
			else if(array[i+7] == '['){
				if(array[i+9] == ']'){
					if(RAM[(int)array[i+8]-48]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					DX = DX/(RAM[(int)array[i+8]-48]);
					indisler[(int)array[i+8]-48] = 0;
					i += 11;
					return i;
				}
				else if(array[i+10] == ']'){
					if(RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					DX = DX/(RAM[((int)array[i+8]-48)*10+((int)array[i+9]-48)]);
					
					indisler[((int)array[i+8]-48)*10+((int)array[i+9]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					if(RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					DX = DX/(RAM[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)]);
					indisler[((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else{
						
				if(((int)array[i+8]-48) == -49|| ((int)array[i+8]-48) == -38){
					
					if(((int)array[i+7]-48)==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					DX = DX/((int)array[i+7]-48);
					i += 9;
					return i;
				}
				else if(((int)array[i+9]-48) == -49|| ((int)array[i+9]-48) == -38){
					DX = DX/(((int)array[i+7]-48)*10+((int)array[i+8]-48));
					i += 10;
					return i;
				}
				else{
					DX = DX/(((int)array[i+7]-48)*100+((int)array[i+8]-48)*10+((int)array[i+9]-48));
					i += 11;
					return i;
				}
			}
		}
		else if(array[i+4] == '['){
		 	
			if(array[i+8] == 'A'){
				RAM[(int)array[i+5]-48] /= AX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == 'B'){
				RAM[(int)array[i+5]-48] /= BX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == 'C'){
				RAM[(int)array[i+5]-48] /= CX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == 'D'){
				RAM[(int)array[i+5]-48] /= DX;
				indisler[(int)array[i+5]-48] = 0;
				i += 11;
				return i;
			}
			else if(array[i+8] == '['){
				if(array[i+10] == ']'){
					if(RAM[(int)array[i+9]-48]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					RAM[(int)array[i+5]-48] /= RAM[(int)array[i+9]-48];
					indisler[(int)array[i+5]-48] = 0;
					indisler[(int)array[i+9]-48] = 0;
					i += 12;
					return i;
				}
				else if(array[i+11] == ']'){
					if(RAM[((int)array[i+9]-48)*10+((int)array[i+10]-48)]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
				    RAM[(int)array[i+5]-48] /= RAM[((int)array[i+9]-48)*10+((int)array[i+10]-48)];
				    indisler[(int)array[i+5]-48] = 0;
				    indisler[((int)array[i+9]-48)*10+((int)array[i+10]-48)] = 0;
					i += 13;
					return i;
				}
				else{
					if(RAM[((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48)]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					RAM[(int)array[i+5]-48]  /= RAM[((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48)];
					indisler[(int)array[i+5]-48] = 0;
					indisler[((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48)] = 0;
					i += 12;
					return i;
				}
			}
			else if(!(array[i+8] == ',') && !(array[i+8] == ']')){
				
				if(((int)array[i+9]-48) == -49 || ((int)array[i+9]-48) == -38 ){
					
					if(RAM[(int)array[i+8]-48]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					
					RAM[(int)array[i+5]-48] /= (int)array[i+8]-48;
					indisler[(int)array[i+5]-48] = 0;
					i += 10;
					return i;
				}
				else if(((int)array[i+10]-48) == -49 || ((int)array[i+10]-48) == -38 ){
					
					RAM[(int)array[i+5]-48] /= ((int)array[i+8]-48)*10+((int)array[i+9]-48);
					indisler[(int)array[i+5]-48] = 0;
					i += 11;
					return i;
				}
				else{
					
					RAM[(int)array[i+5]-48] /= ((int)array[i+8]-48)*100+((int)array[i+9]-48)*10+((int)array[i+10]-48);
					indisler[(int)array[i+5]-48] = 0;
					i += 12;
					return i;
				}
			}
		 	else if(array[i+9] == 'A'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] /= AX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == 'B'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] /= BX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == 'C'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] /= CX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == 'D'){
				RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] /= DX;
				indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				i += 12;
				return i;
			}
			else if(array[i+9] == '['){
				if(array[i+11] == ']'){
					if(RAM[(int)array[i+10]-48]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] /= RAM[(int)array[i+10]-48];
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					indisler[(int)array[i+10]-48] = 0;
					i += 13;
					return i;
				}
				else if(array[i+12] == ']'){
					if(RAM[((int)array[i+10]-48)*10+((int)array[i+11]-48)]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
				    RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] /= RAM[((int)array[i+10]-48)*10+((int)array[i+11]-48)];
				    indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
				    indisler[((int)array[i+10]-48)*10+((int)array[i+11]-48)] = 0;
					i += 14;
					return i;
				}
				else{
					if(RAM[((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48)]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] /= RAM[((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48)];
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					indisler[((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48)] = 0;
					i += 15;
					return i;
				}
			}
			else if(!(array[i+9]==',')){
						
				if(((int)array[i+10]-48) == -49 || ((int)array[i+10]-48) == -38 ){
					if((int)array[i+9]-48==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] /= (int)array[i+9]-48;
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					i += 11;
					return i;
				}
				else if(((int)array[i+11]-48) == -49 || ((int)array[i+11]-48) == -38 ){
					
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] /= ((int)array[i+9]-48)*10+((int)array[i+10]-48);
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					i += 12;
					return i;
				}
				else{
					
					RAM[((int)array[i+5]-48)*10+((int)array[i+6]-48)] /= ((int)array[i+9]-48)*100+((int)array[i+10]-48)*10+((int)array[i+11]-48);
					indisler[((int)array[i+5]-48)*10+((int)array[i+6]-48)] = 0;
					i += 13;
					return i;
				}
			}
			else if(array[i+10] == 'A'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] /= AX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == 'B'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] /= BX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == 'C'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] /= CX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == 'D'){
				RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] /= DX;
				indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
				i += 13;
				return i;
			}
			else if(array[i+10] == '['){
				if(array[i+12] == ']'){
					if(RAM[(int)array[i+11]-48]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] /= RAM[(int)array[i+11]-48];
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					indisler[(int)array[i+11]-48] = 0;
					i += 14;
					return i;
				}
				else if(array[i+13] == ']'){
					if(RAM[((int)array[i+11]-48)*10+((int)array[i+12]-48)]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
				    RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] /= RAM[((int)array[i+11]-48)*10+((int)array[i+12]-48)];
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					indisler[((int)array[i+11]-48)*10+((int)array[i+12]-48)] = 0;
					i += 15;
					return i;
				}
				else{
					if(RAM[((int)array[i+11]-48)*100+((int)array[i+12]-48)*10+((int)array[i+13]-48)]==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] /= RAM[((int)array[i+11]-48)*100+((int)array[i+12]-48)*10+((int)array[i+13]-48)];
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					indisler[((int)array[i+11]-48)*100+((int)array[i+12]-48)*10+((int)array[i+13]-48)] = 0;
					i += 16;
					return i;
				}
			}
			else if(!(array[i+10]==',')){
						
				if(((int)array[i+11]-48) == -49 || ((int)array[i+11]-48) == -38 ){
					
					if((int)array[i+10]-48==0){
						printf("sýfýra boldugunuz icin derlenemedi");
					}
					
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] /= (int)array[i+10]-48;
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					i += 12;
					return i;
				}
				else if(((int)array[i+12]-48) == -49 || ((int)array[i+12]-48) == -38 ){
					
					
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] /= ((int)array[i+10]-48)*10+((int)array[i+11]-48);
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					i += 13;
					return i;
				}
				else{
					RAM[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] /= ((int)array[i+10]-48)*100+((int)array[i+11]-48)*10+((int)array[i+12]-48);
					indisler[((int)array[i+5]-48)*100+((int)array[i+6]-48)*10+((int)array[i+7]-48)] = 0;
					i += 14;
					return i;
				}
			}
		}
	}
}


int main() {

    FILE *fp;
    FILE *fp2;
    
    
    
    struct {
        char token[10];
    } Token[100];
    
    char fileName[]="";
    printf("dosya adini giriniz : ");
    gets(fileName);
    if ((fp = fopen(fileName, "r"))) {
        int j = 0;

        while (!feof(fp)) {
            fgetc(fp);
            j++;
        }
        fclose(fp);

        char array[j];

        fp2 = fopen(fileName, "r");
		
		int i;
		int elemanSayisi = 0;
        for ( i = 0; i < j; ++i) {
            array[i] = getc(fp2);
            elemanSayisi++;
        }

        fclose(fp2);

        int r = 0;
        int l = 0;
        
        int s;
        for ( s = 0; s < j; s++) {
            if (array[s] ==toascii(0x0A) || array[s] == toascii(0x2C) ||  array[s] == toascii(32) || array[s] == toascii(0x3A)) {
                Token[l].token[r] = '\0';
                s++;
                r = 0;
                l++;
            }
            Token[l].token[r++] = array[s];
        }

        char top[]="TOP";
        char crp[]="CRP";
        char atm[]="ATM";
        char bol[]="BOL";
        char cik[]="CIK";
        char ve[]="VE";
        char vey[]="VEY";
        char ds[]="DS";
        char dsd[]="DSD";
        char dal[]="DAL";
        char dk[]="DK";
        char db[]="DB";
        int g=0;
        
        int d;
        for (d = 0; d <  l; d++) {
            switch (Token[d].token[g]) {
                case  'T':
                    CharCompare(top,Token[d].token);//TOP kelimesi kontrol edilir
                    d++;
                    opController(Token[d].token);
                    d++;
                    opController(Token[d].token);
                    break;
                case 'C':
                    if(Token[d].token[g+1]=='R'){ //CRP mi CIK mi olduðu kontrol edilir
                        CharCompare(crp,Token[d].token);//CRP kelimesi kontrol edilir
                        d++;
                        opController(Token[d].token);
                        d++;
                        opController(Token[d].token);
                    } else{
                        CharCompare(cik,Token[d].token);//CIK kelimesi kontrol edilir
                        d++;
                        opController(Token[d].token);
                        d++;
                        opController(Token[d].token);
                    }
                    break;
                case 'A':
                    CharCompare(atm,Token[d].token);//ATM kelimesi kontrol edilir
                    d++;
                    opController(Token[d].token);
                    d++;
                    opController(Token[d].token);
                    break;
                case 'B':
                    CharCompare(bol,Token[d].token);//BOL kelimesi kontrol edilir
                    d++;
                    opController(Token[d].token);
                    d++;
                    opController(Token[d].token);
                    break;
                case 'V':
                    if(Token[d].token[g+2]=='Y'){
                        CharCompare(vey,Token[d].token);
                        d++;
                        opController(Token[d].token);
                        d++;
                        opController(Token[d].token);
                    } else{
                        CharCompare(ve,Token[d].token);
                        d++;
                        opController(Token[d].token);
                        d++;
                        opController(Token[d].token);
                    }
                    break;
                case 'D':
                    if(Token[d].token[g+1]=='S')
                    {
                            if(Token[d].token[g+2]=='D'){
                                CharCompare(dsd,Token[d].token);
                                d++;
                                EtiketController(Token[d].token);
                            } else{
                                CharCompare(ds,Token[d].token);
                                d++;
                                EtiketController(Token[d].token);
                            }
                    }
                    else if(Token[d].token[g+1]=='A')
                    {
                        CharCompare(dal,Token[d].token);
                        d++;
                        EtiketController(Token[d].token);
                    }
                    else if(Token[d].token[g+1]=='K')
                    {
                        CharCompare(dk,Token[d].token);
                        d++;
                        EtiketController(Token[d].token);
                    }
                    else if(Token[d].token[g+1]=='B')
                    {
                        CharCompare(db,Token[d].token);
                        d++;
                        EtiketController(Token[d].token);
                    }
                    break;
                    default:
                    break;
            }
        }
        
        
			
			int e=0;
			for(e;e<256;e++){
				indisler[e] = -1;
			}
			
			i = 0;
			
			while(i<elemanSayisi-1){
				switch(array[i]){
					case 'T':
						i = TOP(i,array);
						break;
						
					case 'C':
						if(array[i+1] == 'I'){
							i = CIK(i,array);
						}else{
							i = CRP(i,array);
						}
						break;
						
					case 'B':
						i = BOL(i,array);
						break;
						
					case 'A':
						i = ATM(i,array);
						break;	
					
					case 'V':
						if(array[i+2] == 'Y'){
							i = VEY(i,array);
						}
						else{
							i = VE(i,array);
						}
						
						break;	
						
					default:
						i++;
						break;
				}
			}
			
			
			printf("\nAX = %d",AX);
			printf("\nBX = %d",BX);
			printf("\nCX = %d",CX);
			printf("\nDX = %d\n",DX);
			
			
			int z;
			for(z=0;z<256;z++){
				if(indisler[z] != -1){
					printf("\nRAM[%d] = %d",z,RAM[z]);
				}
			}
	
}
    else {
        printf("dosya bulunamadi");
    }

}

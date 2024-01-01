#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<windows.h> 
using namespace std;

struct PELICULA{
	string pelicula;
	int hora;
	int minutos;
	string protagonistas1;
	string protagonistas2;
	string Calificacion;
	string dia;
	PELICULA *ant;
	PELICULA *sgt;
};

struct SESIONES{
	int NSecciones;
	PELICULA *pcabPelicula;
	PELICULA *pfinPelicula;
	SESIONES *ant;
	SESIONES *sgt;
};
struct SALAS{
	int NSala;
	SESIONES *pcabSesiones;
	SESIONES *pfinSesiones;
	SALAS *ant;
	SALAS *sgt;
};
struct CINE{
	string Cine;
	CINE *siguiente;
	CINE *anterior;
	SALAS *pcabSala;
	SALAS *pfinSala;
};

int menu();
void operaciones(CINE *&pcab,CINE *&pfin,int op);
void registrociness(CINE *&pcab,CINE *&pfin);
void registrocines(CINE *&pcab,CINE *&pfin,string cines);
CINE *buscarCINE(CINE *pcab,string cines);
void MOSTARCINE(CINE *pcab);
void registrosalas(SALAS *&pcabSala,SALAS *&pfinSala,int sala);
SALAS *buscarsala(SALAS *pcabSala,int sala);
void MOSTARSALAS(SALAS *pcabSala);
SESIONES *buscarsesion(SESIONES *pcabSesiones,int sesion);
void registrosesion(SESIONES *&pcabSesiones,SESIONES *&pfinSesiones,int sesion);
void MOSTARSESIONES(SESIONES *pcabSesiones);
void registropelicula(PELICULA *&pcabPelicula,PELICULA *&pfinPelicula);
PELICULA *buscarDia(PELICULA *pcabPelicula,string respDia);
void modificarPelicula(PELICULA *&pcabPelicula,PELICULA *&pfinPelicula);

int main(){
	system("color 0b");
	CINE *pcab=NULL, *pfin=NULL;
	registrociness(pcab,pfin);
	int op;
	do{
		system("cls");
		op=menu();
		operaciones(pcab,pfin,op);
		cout<<"\nDesea realizar otra operacion si(1)-no(otro): ";
		cin>>op;
		cin.get();
	}while(op==1);
	return 0;
}

void operaciones(CINE *&pcab,CINE *&pfin,int op){
	int resp,sesion,sala;
    string cines,respDia;
    CINE *dirCine;
    SALAS *dirSala;
    SESIONES *dirSesiones;
    PELICULA *dirpeli,*dirPelicula2;
	switch(op){
		case 1:
			system("cls");
			cout<<"\n ***********************************"<<endl;
        	cout<<" ********  REGISTRO DE CINE  *******"<<endl;
        	cout<<" ***********************************"<<endl;
        	cout<<"\n INGRESE EL NOMBRE DEL CINE A REGISTAR: "<<endl;
	        cin>>cines;
			dirCine=buscarCINE(pcab,cines);
			if(dirCine==NULL){
			    registrocines(pcab,pfin,cines);
			}else{
			    cout<<"\n ERROR YA EXISTE ESTE CINE.............."<<endl;
			}
			break;
		case 2:
			system("cls");
			cout<<"\n***********************************"<<endl;
        	cout<<"*******  REGISTRO DE SALAS  *******"<<endl;
        	cout<<"***********************************"<<endl;
        	cout<<"\n***********************************"<<endl;
        	cout<<"******** CINES DISPONIBLES ********"<<endl;
        	cout<<"***********************************"<<endl;
			MOSTARCINE(pcab);
			cout<<"***********************************"<<endl;
        	cout<<"\nDIGITE EL NOMBRE DEL CINE: "<<endl;
	        cin>>cines;
			dirCine=buscarCINE(pcab,cines);
			if(dirCine==NULL){
				cout<<"\nERROR EL CINE NO SE ENCUENTRA REGISTRADO.............."<<endl;
			}else{
				resp=1;
			    while(resp==1){
				    cout<<"\nINGRESE EL NUMERO DE LA SALA A REGISTAR: "<<endl;
	                cin>>sala;
			        dirSala=buscarsala(dirCine->pcabSala,sala);
			        if(dirSala==NULL){
				        registrosalas(dirCine->pcabSala,dirCine->pfinSala,sala);
				    }else{
			            cout<<"\nERROR YA EXISTE LA SALA.............."<<endl;
		            }
			        cout<<"\nDESEA REGISTRAR OTRA SALA SI(1)-NO(OTRO NUMERO): ";
			        cin>>resp;
			    }
			}
			break;
		case 3:
			system("cls");
			cout<<"\n***********************************"<<endl;
        	cout<<"*******  REGISTRO DE SESION  *******"<<endl;
        	cout<<"***********************************"<<endl;
        	cout<<"\n***********************************"<<endl;
        	cout<<"******** CINES DISPONIBLES ********"<<endl;
        	cout<<"***********************************"<<endl;
			MOSTARCINE(pcab);
			cout<<"***********************************"<<endl;
        	cout<<"\nDIGITE EL NOMBRE DEL CINE: "<<endl;
	        cin>>cines;
			dirCine=buscarCINE(pcab,cines);
			if(dirCine==NULL){
				cout<<"\nERROR EL CINE NO SE ENCUENTRA REGISTRADO.............."<<endl;
			}else{
			    cout<<"\n***********************************"<<endl;
                cout<<"******** SALAS DISPONIBLES ********"<<endl;
                cout<<"***********************************"<<endl;
                MOSTARSALAS(dirCine->pcabSala);
                cout<<"***********************************"<<endl;
				cout<<"\nDIGITE EL NUMERO DE LA SALA: "<<endl;
	            cin>>sala;
			    dirSala=buscarsala(dirCine->pcabSala,sala);
			    if(dirSala==NULL){
				    cout<<"\nERROR LA SALA NO SE ENCUENTRA REGISTRADO.............."<<endl;
				}else{
			        resp=1;
			    	while(resp==1){
				        cout<<"\nINGRESE EL NUMERO DE LA SESION A REGISTAR: "<<endl;
	                    cin>>sesion;
			            dirSesiones=buscarsesion(dirSala->pcabSesiones,sesion);
			            if(dirSesiones==NULL){
				    	    registrosesion(dirSala->pcabSesiones,dirSala->pfinSesiones,sesion);
				        }else{
			                cout<<"\nERROR YA EXISTE LA SESION.............."<<endl;
		                }
			            cout<<"\n\nDESEA REGISTRAR OTRA SESION SI(1)-NO(OTRO NUMERO): ";
				        cin>>resp;
			        }
		        }
			}
			break;
		case 4:
			cout<<"\n***********************************"<<endl;
        	cout<<"*****  REGISTRO DE PELICULAS ******"<<endl;
        	cout<<"***********************************"<<endl;
        	cout<<"\n***********************************"<<endl;
        	cout<<"******** CINES DISPONIBLES ********"<<endl;
        	cout<<"***********************************"<<endl;
			MOSTARCINE(pcab);
			cout<<"***********************************"<<endl;
        	cout<<"\nDIGITE EL NOMBRE DEL CINE: "<<endl;
	        cin>>cines;
			dirCine=buscarCINE(pcab,cines);
			if(dirCine==NULL){
				cout<<"\nERROR EL CINE NO SE ENCUENTRA REGISTRADO.............."<<endl;
			}else{
			    cout<<"\n***********************************"<<endl;
                cout<<"******** SALAS DISPONIBLES ********"<<endl;
                cout<<"***********************************"<<endl;
                MOSTARSALAS(dirCine->pcabSala);
                cout<<"***********************************"<<endl;
				cout<<"\nDIGITE EL NUMERO DE LA SALA: "<<endl;
	            cin>>sala;
			    dirSala=buscarsala(dirCine->pcabSala,sala);
			    if(dirSala==NULL){
				    cout<<"\nERROR LA SALA NO SE ENCUENTRA REGISTRADO.............."<<endl;
				}else{
					cout<<"\n***********************************"<<endl;
                    cout<<"****** SESIONES DISPONIBLES *******"<<endl;
                    cout<<"***********************************"<<endl;
                    MOSTARSESIONES(dirSala->pcabSesiones);
                    cout<<"***********************************"<<endl;
				    cout<<"\nDIGITE EL NUMERO DE LA SESION: "<<endl;
	                cin>>sesion;
			        dirSesiones=buscarsesion(dirSala->pcabSesiones,sesion);
			        if(dirSesiones==NULL){
				    	cout<<"\nERROR LA SESION NO SE ENCUENTRA REGISTRADO.............."<<endl;
				    }else{
				    	resp=1;
			        	while(resp==1){
			        		cout<<"***********************************"<<endl;
			        		cout<<"REGISTRE DETALLES DE LA PELICULA"<<endl;
				            registropelicula(dirSesiones->pcabPelicula,dirSesiones->pfinPelicula);
			                cout<<"\n\nDESEA REGISTRAR OTRA PELICULA SI(1)-NO(OTRO NUMERO): ";
				            cin>>resp;
			           }
			            
		            }     
		        }
			}
			break;
		case 5:
			cout<<"\n INGRESE EL NOMBRE DEL CINE: "<<endl;
	        cin>>cines;
			dirCine=buscarCINE(pcab,cines);
			if(dirCine==NULL){
			    cout<<"Cine no registrado";
			    break;
			}else{
				cout<<"\nINGRESE EL NUMERO DE LA SALA: "<<endl;
	            cin>>sala;
			    dirSala=buscarsala(dirCine->pcabSala,sala);
			    if(dirSala==NULL){
				    cout<<"Sala no registrada";
				}else{
			    	cout<<"\nDIGITE EL NUMERO DE LA SESION: "<<endl;
	                cin>>sesion;
			        dirSesiones=buscarsesion(dirSala->pcabSesiones,sesion);
			        if(dirSesiones==NULL){
				    	cout<<"\nERROR LA SESION NO SE ENCUENTRA REGISTRADO."<<endl;
				    }else{
				    	cout<<"Ingrese el dia: ";
				    	cin>>respDia;
				    	dirPelicula2=buscarDia(dirSesiones->pcabPelicula,respDia);
				    	if(dirPelicula2==NULL){
				    		cout<<"\nERROR DIA NO ENCONTRADO."<<endl;
						}else{
							cout<<"\tPelicula "<<dirPelicula2->pelicula<<endl;
							cout<<"\tHora: "<<dirPelicula2->hora<<":"<<dirPelicula2->minutos<<"h"<<endl;
							cout<<"\tProtagonista 1: "<<dirPelicula2->protagonistas1<<endl;
							cout<<"\tProtagonista 2: "<<dirPelicula2->protagonistas2<<endl;
							cout<<"\tClasificacion: "<<dirPelicula2->Calificacion<<endl;
				  		
						}
			        }	
		        }
			}
			break;
		case 6:
		{
			string PeliculaNom;
			cout<<"\n INGRESE EL NOMBRE DE LA PELICULA: "<<endl;
	        cin>>PeliculaNom;
	        CINE *pCine=pcab;
	        while(pCine!=NULL){
	        	SALAS *pSala=pCine->pcabSala;
	        	while(pSala!=NULL){
	        		SESIONES *pSesion=pSala->pcabSesiones;
	        		while(pSesion!=NULL){
	        			PELICULA *pPeli=pSesion->pcabPelicula;
	        			while(pPeli!=NULL){
	        				if(pPeli->pelicula==PeliculaNom){
	        					cout<<"\tPelicula: "<<pPeli->pelicula<<endl;
	        					cout<<"\tSe proyecta en"<<endl;
	        					cout<<"\tEl cine "<<pcab->Cine<<",el "<<pPeli->dia<<", en la sala "<<pSala->NSala<<"y en la sesion "<<pSesion->NSecciones<<""<<endl;
	        					cout<<"\tHora: "<<pPeli->hora<<":"<<pPeli->minutos<<"h"<<endl;	
							}
	        				pPeli=pPeli->sgt;
						}
						pSesion=pSesion->sgt;
					}
					pSala=pSala->sgt;
				}
				pCine=pCine->siguiente;
			}
			break;
		}
		case 7:
			{
			string PeliculaNom;
			int SalaNom;
			cout<<"\n INGRESE EL NOMBRE DE LA PELICULA: ";
	        cin>>PeliculaNom;
	        cout<<"\n INGRESE EL NUMERO DE LA SALA: ";
	        cin>>SalaNom;
	        CINE *pCine=pcab;
	        while(pCine!=NULL){
	        	SALAS *pSala=pCine->pcabSala;
	        	while(pSala!=NULL){
	        		SESIONES *pSesion=pSala->pcabSesiones;
	        		while(pSesion!=NULL){
	        			PELICULA *pPeli=pSesion->pcabPelicula;
	        			while(pPeli!=NULL){
	        				if(pPeli->pelicula==PeliculaNom and pSala->NSala==SalaNom){
	        				modificarPelicula(pPeli,pSesion->pfinPelicula);		
							}
	        				pPeli=pPeli->sgt;
						}
						pSesion=pSesion->sgt;
					}
					pSala=pSala->sgt;
				}
				pCine=pCine->siguiente;
			}
		}
			break;	
		case 8:
			{
			string calificacion;
			int cont, opp;
			do{
			cout<<"\n***********************************"<<endl;
			cout<<"********* CALIFICACION ************"<<endl;
			cout<<"***********************************"<<endl;
			cout<<"  1. TODOS LOS PUBLICOS (TP)"<<endl;
			cout<<"  2. MAYORES DE 13 AÑOS (M13)"<<endl;
			cout<<"  3. MAYORES DE 18 AÑOS (M18)"<<endl;
			cout<<"***********************************"<<endl;
	    	cout<<"\nINGRESE LA CALIFICACION: ";
	    	cin>>opp;
			}while(opp<1 || opp>3);
			
			if(opp==1){
				calificacion="TP";
			}
			if(opp==2){
				calificacion="M13";
			}
			if(opp==3){
				calificacion="M18";
			}
				
	        CINE *pCine=pcab;
	        while(pCine!=NULL){
	        	cont=0;
	        	cout<<"Cine: "<<pCine->Cine;
	        	SALAS *pSala=pCine->pcabSala;
	        	while(pSala!=NULL){
	        		SESIONES *pSesion=pSala->pcabSesiones;
	        		while(pSesion!=NULL){
	        			PELICULA *pPeli=pSesion->pcabPelicula;
	        			while(pPeli!=NULL){
	        				if(pPeli->Calificacion==calificacion){
	        					cont=1;
	        					cout<<"\tSala: "<<pSala->NSala<<endl;
	        					cout<<"\tSesion: "<<pSesion->NSecciones<<endl;
	        					cout<<"\tDia: "<<pPeli->dia<<endl;
	        					cout<<"\tPelicula: "<<pPeli->pelicula<<endl;
	        					cout<<"\tHora: "<<pPeli->hora<<":"<<pPeli->minutos<<"h"<<endl;
	        					cout<<endl;
							}
	        				pPeli=pPeli->sgt;
						}
						pSesion=pSesion->sgt;
					}
					pSala=pSala->sgt;
				}
				if(cont==0){
					cout<<endl;
					cout<<"\tNo existen"<<endl;
					
				}
				cout<<endl;
				pCine=pCine->siguiente;
			}
		}
			break;
		case 9:
			{
			int cont;	
	        CINE *pCine=pcab;
	        while(pCine!=NULL){
	        	cont=0;
	        	cout<<"Cine: "<<pCine->Cine;
	        	SALAS *pSala=pCine->pcabSala;
	        	while(pSala!=NULL){
	        		SESIONES *pSesion=pSala->pcabSesiones;
	        		while(pSesion!=NULL){
	        			PELICULA *pPeli=pSesion->pcabPelicula;
	        			while(pPeli!=NULL){
	        					cont=1;
	        					cout<<"Sala: "<<pSala->NSala<<endl;
	        					cout<<"Sesion: "<<pSesion->NSecciones<<endl;
	        					cout<<"Dia: "<<pPeli->dia<<endl;
	        					cout<<"Pelicula: "<<pPeli->pelicula<<endl;
	        					cout<<"Protegonista 1: "<<pPeli->protagonistas1<<endl;
	        					cout<<"Protagonista 2: "<<pPeli->protagonistas2<<endl;
	        					cout<<"Hora: "<<pPeli->hora<<":"<<pPeli->minutos<<"h"<<endl;
	        					cout<<"Clasificacion: "<<pPeli->Calificacion<<endl;
	        					cout<<endl;
	        				pPeli=pPeli->sgt;
						}
						pSesion=pSesion->sgt;
					}
					pSala=pSala->sgt;
				}
				if(cont==0){
					cout<<endl;
					cout<<"\tNo existen"<<endl;
					
				}
				cout<<endl;
				pCine=pCine->siguiente;
			}
		}
			break;
		case 10:
		    char salir;
		    system("cls");
			cout<<"\n***********************************"<<endl;
        	cout<<"*******  SALIR DEL PROGRAMA  *******"<<endl;
        	cout<<"***********************************"<<endl;
		    printf("\nEsta seguro de salir (s/n)?");
            fflush(stdin);
            scanf("%c", &salir);
            if (salir == 's' || salir == 'S'){
            	cout<<" GRACIAS............................!!"<<endl;
                exit(-1);
            }
            getch();
			break;	  	  			    		  
	}	
}
PELICULA *buscarDia(PELICULA *pcabPelicula,string respDia){
	PELICULA *nodoAct=pcabPelicula;
	while(nodoAct!=NULL){
		if(nodoAct->dia==respDia){
		return nodoAct;
	}
	nodoAct=nodoAct->sgt;
	}
	return NULL;	
}


void modificarPelicula(PELICULA *&pcabPelicula,PELICULA *&pfinPelicula){
	string pelicula;
	string dia;
	int dias;
	int hora;
	int minutos;
	string protagonistas1;
	string protagonistas2;
    string Calificacion;
    int opp;
	PELICULA *newPelicula;
	cout<<"\n***********************************"<<endl;
	cout<<"\nINGRESE EL NOMBRE DE LA PELICULA A MODIFICAR: ";
	fflush(stdin);
	getline(cin,pelicula);
	do{
	cout<<"\n***********************************"<<endl;
	cout<<"************** DIAS ***************"<<endl;
	cout<<"***********************************"<<endl;
	cout<<" 1. Lunes "<<endl;
	cout<<" 2. Martes "<<endl;
	cout<<" 3. Miercoles "<<endl;
	cout<<" 4. Jueves "<<endl;
	cout<<" 5. Viernes "<<endl;
	cout<<" 6. Sabado "<<endl;
	cout<<" 7. Domingo "<<endl;
	cout<<"***********************************"<<endl;
	cout<<"\nDIGITE EL NUMERO DEL DIA: "<<endl;
	cin>>dias;
	}while(dias<1 || dias>7);
	switch(dias){
			case 1:
			dia="Lunes";
			do{
    	    	cout<<"INGRESE LA HORA: ";
    	        cin>>hora;
    	    }while(hora<1 || hora>24);
        	do{
    	    	cout<<"CON SUS MINUTOS: ";
    	        cin>>minutos;
        	}while(minutos<0 || minutos>59);
            	cout<<"INGRESE EL PROTAGONISTA N°1: ";
            	fflush(stdin);
            	getline(cin,protagonistas1);
            	cout<<"INGRESE EL PROTAGONISTA N°2: ";
            	fflush(stdin);
            	getline(cin,protagonistas2);
    		do{
		    	cout<<"\n***********************************"<<endl;
				cout<<"********* CALIFICACION ************"<<endl;
				cout<<"***********************************"<<endl;
				cout<<"  1. TODOS LOS PUBLICOS (TP)"<<endl;
				cout<<"  2. MAYORES DE 13 AÑOS (M13)"<<endl;
				cout<<"  3. MAYORES DE 18 AÑOS (M18)"<<endl;
				cout<<"***********************************"<<endl;
	    		cout<<"\nINGRESE LA CALIFICACION: ";
	    		cin>>opp;
			}while(opp<1 || opp>3);
			switch(opp){
				case 1:
					Calificacion= "TP";
			    	newPelicula=new(PELICULA);
        	    	newPelicula->pelicula=pelicula;
        	    	newPelicula->dia=dia;
        	    	newPelicula->hora=hora;
        	    	newPelicula->minutos=minutos;
        	    	newPelicula->protagonistas1=protagonistas1;
        	    	newPelicula->protagonistas2=protagonistas2;
        	    	newPelicula->Calificacion=Calificacion;
        	    	newPelicula->sgt=NULL;
        	    	newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		        		pcabPelicula=newPelicula;		
        	    	}else{
		                pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	    	    	}	
	        	    	pfinPelicula=newPelicula;
		        	break;
		    	case 2:
		    		Calificacion= "M13";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		            	pcabPelicula=newPelicula;		
            		}else{
		     	        pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	            	}	
	            	pfinPelicula=newPelicula;
		        	break;
		    	case 3:
		        	Calificacion= "M18";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
	    		    	pcabPelicula=newPelicula;		
            		}else{
	    		        pfinPelicula->sgt=newPelicula;
	    		        newPelicula->ant=pfinPelicula;
	     	       	}	
	    	        pfinPelicula=newPelicula;
		        	break;
	                }
			break;
			case 2:
			dia="Martes";
			do{
    	    	cout<<"INGRESE LA HORA: ";
    	        cin>>hora;
    	    }while(hora<1 || hora>24);
        	do{
    	    	cout<<"CON SUS MINUTOS: ";
    	        cin>>minutos;
        	}while(minutos<0 || minutos>59);
            	cout<<"INGRESE EL PROTAGONISTA N°1: ";
            	fflush(stdin);
            	getline(cin,protagonistas1);
            	cout<<"INGRESE EL PROTAGONISTA N°2: ";
            	fflush(stdin);
            	getline(cin,protagonistas2);
    		do{
		    	cout<<"\n***********************************"<<endl;
				cout<<"********* CALIFICACION ************"<<endl;
				cout<<"***********************************"<<endl;
				cout<<"  1. TODOS LOS PUBLICOS (TP)"<<endl;
				cout<<"  2. MAYORES DE 13 AÑOS (M13)"<<endl;
				cout<<"  3. MAYORES DE 18 AÑOS (M18)"<<endl;
				cout<<"***********************************"<<endl;
	    		cout<<"\nINGRESE LA CALIFICACION: ";
	    		cin>>opp;
			}while(opp<1 || opp>3);
			switch(opp){
				case 1:
					Calificacion= "TP";
			    	newPelicula=new(PELICULA);
        	    	newPelicula->pelicula=pelicula;
        	    	newPelicula->dia=dia;
        	    	newPelicula->hora=hora;
        	    	newPelicula->minutos=minutos;
        	    	newPelicula->protagonistas1=protagonistas1;
        	    	newPelicula->protagonistas2=protagonistas2;
        	    	newPelicula->Calificacion=Calificacion;
        	    	newPelicula->sgt=NULL;
        	    	newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		        		pcabPelicula=newPelicula;		
        	    	}else{
		                pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	    	    	}	
	        	    	pfinPelicula=newPelicula;
		        	break;
		    	case 2:
		    		Calificacion= "M13";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		            	pcabPelicula=newPelicula;		
            		}else{
		     	        pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	            	}	
	            	pfinPelicula=newPelicula;
		        	break;
		    	case 3:
		        	Calificacion= "M18";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
	    		    	pcabPelicula=newPelicula;		
            		}else{
	    		        pfinPelicula->sgt=newPelicula;
	    		        newPelicula->ant=pfinPelicula;
	     	       	}	
	    	        pfinPelicula=newPelicula;
		        	break;
	                }
			break;
			case 3:
			dia="Miercoles";
			do{
    	    	cout<<"INGRESE LA HORA: ";
    	        cin>>hora;
    	    }while(hora<1 || hora>24);
        	do{
    	    	cout<<"CON SUS MINUTOS: ";
    	        cin>>minutos;
        	}while(minutos<0 || minutos>59);
            	cout<<"INGRESE EL PROTAGONISTA N°1: ";
            	fflush(stdin);
            	getline(cin,protagonistas1);
            	cout<<"INGRESE EL PROTAGONISTA N°2: ";
            	fflush(stdin);
            	getline(cin,protagonistas2);
    		do{
		    	cout<<"\n***********************************"<<endl;
				cout<<"********* CALIFICACION ************"<<endl;
				cout<<"***********************************"<<endl;
				cout<<"  1. TODOS LOS PUBLICOS (TP)"<<endl;
				cout<<"  2. MAYORES DE 13 AÑOS (M13)"<<endl;
				cout<<"  3. MAYORES DE 18 AÑOS (M18)"<<endl;
				cout<<"***********************************"<<endl;
	    		cout<<"\nINGRESE LA CALIFICACION: ";
	    		cin>>opp;
			}while(opp<1 || opp>3);
			switch(opp){
				case 1:
					Calificacion= "TP";
			    	newPelicula=new(PELICULA);
        	    	newPelicula->pelicula=pelicula;
        	    	newPelicula->dia=dia;
        	    	newPelicula->hora=hora;
        	    	newPelicula->minutos=minutos;
        	    	newPelicula->protagonistas1=protagonistas1;
        	    	newPelicula->protagonistas2=protagonistas2;
        	    	newPelicula->Calificacion=Calificacion;
        	    	newPelicula->sgt=NULL;
        	    	newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		        		pcabPelicula=newPelicula;		
        	    	}else{
		                pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	    	    	}	
	        	    	pfinPelicula=newPelicula;
		        	break;
		    	case 2:
		    		Calificacion= "M13";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		            	pcabPelicula=newPelicula;		
            		}else{
		     	        pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	            	}	
	            	pfinPelicula=newPelicula;
		        	break;
		    	case 3:
		        	Calificacion= "M18";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
	    		    	pcabPelicula=newPelicula;		
            		}else{
	    		        pfinPelicula->sgt=newPelicula;
	    		        newPelicula->ant=pfinPelicula;
	     	       	}	
	    	        pfinPelicula=newPelicula;
		        	break;
	                }
			break;
			case 4:
			dia="Jueves";
			do{
    	    	cout<<"INGRESE LA HORA: ";
    	        cin>>hora;
    	    }while(hora<1 || hora>24);
        	do{
    	    	cout<<"CON SUS MINUTOS: ";
    	        cin>>minutos;
        	}while(minutos<0 || minutos>59);
            	cout<<"INGRESE EL PROTAGONISTA N°1: ";
            	fflush(stdin);
            	getline(cin,protagonistas1);
            	cout<<"INGRESE EL PROTAGONISTA N°2: ";
            	fflush(stdin);
            	getline(cin,protagonistas2);
    		do{
		    	cout<<"\n***********************************"<<endl;
				cout<<"********* CALIFICACION ************"<<endl;
				cout<<"***********************************"<<endl;
				cout<<"  1. TODOS LOS PUBLICOS (TP)"<<endl;
				cout<<"  2. MAYORES DE 13 AÑOS (M13)"<<endl;
				cout<<"  3. MAYORES DE 18 AÑOS (M18)"<<endl;
				cout<<"***********************************"<<endl;
	    		cout<<"\nINGRESE LA CALIFICACION: ";
	    		cin>>opp;
			}while(opp<1 || opp>3);
			switch(opp){
				case 1:
					Calificacion= "TP";
			    	newPelicula=new(PELICULA);
        	    	newPelicula->pelicula=pelicula;
        	    	newPelicula->dia=dia;
        	    	newPelicula->hora=hora;
        	    	newPelicula->minutos=minutos;
        	    	newPelicula->protagonistas1=protagonistas1;
        	    	newPelicula->protagonistas2=protagonistas2;
        	    	newPelicula->Calificacion=Calificacion;
        	    	newPelicula->sgt=NULL;
        	    	newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		        		pcabPelicula=newPelicula;		
        	    	}else{
		                pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	    	    	}	
	        	    	pfinPelicula=newPelicula;
		        	break;
		    	case 2:
		    		Calificacion= "M13";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		            	pcabPelicula=newPelicula;		
            		}else{
		     	        pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	            	}	
	            	pfinPelicula=newPelicula;
		        	break;
		    	case 3:
		        	Calificacion= "M18";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
	    		    	pcabPelicula=newPelicula;		
            		}else{
	    		        pfinPelicula->sgt=newPelicula;
	    		        newPelicula->ant=pfinPelicula;
	     	       	}	
	    	        pfinPelicula=newPelicula;
		        	break;
	                }
			break;
			case 5:
			dia="Viernes";
			do{
    	    	cout<<"INGRESE LA HORA: ";
    	        cin>>hora;
    	    }while(hora<1 || hora>24);
        	do{
    	    	cout<<"CON SUS MINUTOS: ";
    	        cin>>minutos;
        	}while(minutos<0 || minutos>59);
            	cout<<"INGRESE EL PROTAGONISTA N°1: ";
            	fflush(stdin);
            	getline(cin,protagonistas1);
            	cout<<"INGRESE EL PROTAGONISTA N°2: ";
            	fflush(stdin);
            	getline(cin,protagonistas2);
    		do{
		    	cout<<"\n***********************************"<<endl;
				cout<<"********* CALIFICACION ************"<<endl;
				cout<<"***********************************"<<endl;
				cout<<"  1. TODOS LOS PUBLICOS (TP)"<<endl;
				cout<<"  2. MAYORES DE 13 AÑOS (M13)"<<endl;
				cout<<"  3. MAYORES DE 18 AÑOS (M18)"<<endl;
				cout<<"***********************************"<<endl;
	    		cout<<"\nINGRESE LA CALIFICACION: ";
	    		cin>>opp;
			}while(opp<1 || opp>3);
			switch(opp){
				case 1:
					Calificacion= "TP";
			    	newPelicula=new(PELICULA);
        	    	newPelicula->pelicula=pelicula;
        	    	newPelicula->dia=dia;
        	    	newPelicula->hora=hora;
        	    	newPelicula->minutos=minutos;
        	    	newPelicula->protagonistas1=protagonistas1;
        	    	newPelicula->protagonistas2=protagonistas2;
        	    	newPelicula->Calificacion=Calificacion;
        	    	newPelicula->sgt=NULL;
        	    	newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		        		pcabPelicula=newPelicula;		
        	    	}else{
		                pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	    	    	}	
	        	    	pfinPelicula=newPelicula;
		        	break;
		    	case 2:
		    		Calificacion= "M13";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		            	pcabPelicula=newPelicula;		
            		}else{
		     	        pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	            	}	
	            	pfinPelicula=newPelicula;
		        	break;
		    	case 3:
		        	Calificacion= "M18";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
	    		    	pcabPelicula=newPelicula;		
            		}else{
	    		        pfinPelicula->sgt=newPelicula;
	    		        newPelicula->ant=pfinPelicula;
	     	       	}	
	    	        pfinPelicula=newPelicula;
		        	break;
	                }
			break;
			case 6:
			dia="Sabado";
			do{
    	    	cout<<"INGRESE LA HORA: ";
    	        cin>>hora;
    	    }while(hora<1 || hora>24);
        	do{
    	    	cout<<"CON SUS MINUTOS: ";
    	        cin>>minutos;
        	}while(minutos<0 || minutos>59);
            	cout<<"INGRESE EL PROTAGONISTA N°1: ";
            	fflush(stdin);
            	getline(cin,protagonistas1);
            	cout<<"INGRESE EL PROTAGONISTA N°2: ";
            	fflush(stdin);
            	getline(cin,protagonistas2);
    		do{
		    	cout<<"\n***********************************"<<endl;
				cout<<"********* CALIFICACION ************"<<endl;
				cout<<"***********************************"<<endl;
				cout<<"  1. TODOS LOS PUBLICOS (TP)"<<endl;
				cout<<"  2. MAYORES DE 13 AÑOS (M13)"<<endl;
				cout<<"  3. MAYORES DE 18 AÑOS (M18)"<<endl;
				cout<<"***********************************"<<endl;
	    		cout<<"\nINGRESE LA CALIFICACION: ";
	    		cin>>opp;
			}while(opp<1 || opp>3);
			switch(opp){
				case 1:
					Calificacion= "TP";
			    	newPelicula=new(PELICULA);
        	    	newPelicula->pelicula=pelicula;
        	    	newPelicula->dia=dia;
        	    	newPelicula->hora=hora;
        	    	newPelicula->minutos=minutos;
        	    	newPelicula->protagonistas1=protagonistas1;
        	    	newPelicula->protagonistas2=protagonistas2;
        	    	newPelicula->Calificacion=Calificacion;
        	    	newPelicula->sgt=NULL;
        	    	newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		        		pcabPelicula=newPelicula;		
        	    	}else{
		                pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	    	    	}	
	        	    	pfinPelicula=newPelicula;
		        	break;
		    	case 2:
		    		Calificacion= "M13";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		            	pcabPelicula=newPelicula;		
            		}else{
		     	        pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	            	}	
	            	pfinPelicula=newPelicula;
		        	break;
		    	case 3:
		        	Calificacion= "M18";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
	    		    	pcabPelicula=newPelicula;		
            		}else{
	    		        pfinPelicula->sgt=newPelicula;
	    		        newPelicula->ant=pfinPelicula;
	     	       	}	
	    	        pfinPelicula=newPelicula;
		        	break;
	                }
			break;
			case 7:
			dia="Domingo";
			do{
    	    	cout<<"INGRESE LA HORA: ";
    	        cin>>hora;
    	    }while(hora<1 || hora>24);
        	do{
    	    	cout<<"CON SUS MINUTOS: ";
    	        cin>>minutos;
        	}while(minutos<0 || minutos>59);
            	cout<<"INGRESE EL PROTAGONISTA N°1: ";
            	fflush(stdin);
            	getline(cin,protagonistas1);
            	cout<<"INGRESE EL PROTAGONISTA N°2: ";
            	fflush(stdin);
            	getline(cin,protagonistas2);
    		do{
		    	cout<<"\n***********************************"<<endl;
				cout<<"********* CALIFICACION ************"<<endl;
				cout<<"***********************************"<<endl;
				cout<<"  1. TODOS LOS PUBLICOS (TP)"<<endl;
				cout<<"  2. MAYORES DE 13 AÑOS (M13)"<<endl;
				cout<<"  3. MAYORES DE 18 AÑOS (M18)"<<endl;
				cout<<"***********************************"<<endl;
	    		cout<<"\nINGRESE LA CALIFICACION: ";
	    		cin>>opp;
			}while(opp<1 || opp>3);
			switch(opp){
				case 1:
					Calificacion= "TP";
			    	newPelicula=new(PELICULA);
        	    	newPelicula->pelicula=pelicula;
        	    	newPelicula->dia=dia;
        	    	newPelicula->hora=hora;
        	    	newPelicula->minutos=minutos;
        	    	newPelicula->protagonistas1=protagonistas1;
        	    	newPelicula->protagonistas2=protagonistas2;
        	    	newPelicula->Calificacion=Calificacion;
        	    	newPelicula->sgt=NULL;
        	    	newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		        		pcabPelicula=newPelicula;		
        	    	}else{
		                pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	    	    	}	
	        	    	pfinPelicula=newPelicula;
		        	break;
		    	case 2:
		    		Calificacion= "M13";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		            	pcabPelicula=newPelicula;		
            		}else{
		     	        pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	            	}	
	            	pfinPelicula=newPelicula;
		        	break;
		    	case 3:
		        	Calificacion= "M18";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
	    		    	pcabPelicula=newPelicula;		
            		}else{
	    		        pfinPelicula->sgt=newPelicula;
	    		        newPelicula->ant=pfinPelicula;
	     	       	}	
	    	        pfinPelicula=newPelicula;
		        	break;
	                }
			break;	
    }
}



void registropelicula(PELICULA *&pcabPelicula,PELICULA *&pfinPelicula){
	string pelicula;
	string dia;
	int dias;
	int hora;
	int minutos;
	string protagonistas1;
	string protagonistas2;
    string Calificacion;
    int opp;
	PELICULA *newPelicula;
	cout<<"\n***********************************"<<endl;
	cout<<"\nINGRESE EL NOMBRE DE LA PELICULA: ";
	fflush(stdin);
	getline(cin,pelicula);
	do{
	cout<<"\n***********************************"<<endl;
	cout<<"************** DIAS ***************"<<endl;
	cout<<"***********************************"<<endl;
	cout<<" 1. Lunes "<<endl;
	cout<<" 2. Martes "<<endl;
	cout<<" 3. Miercoles "<<endl;
	cout<<" 4. Jueves "<<endl;
	cout<<" 5. Viernes "<<endl;
	cout<<" 6. Sabado "<<endl;
	cout<<" 7. Domingo "<<endl;
	cout<<"***********************************"<<endl;
	cout<<"\nDIGITE EL NUMERO DEL DIA: "<<endl;
	cin>>dias;
	}while(dias<1 || dias>7);
	switch(dias){
			case 1:
			dia="Lunes";
			do{
    	    	cout<<"INGRESE LA HORA: ";
    	        cin>>hora;
    	    }while(hora<1 || hora>24);
        	do{
    	    	cout<<"CON SUS MINUTOS: ";
    	        cin>>minutos;
        	}while(minutos<0 || minutos>59);
            	cout<<"INGRESE EL PROTAGONISTA N°1: ";
            	fflush(stdin);
            	getline(cin,protagonistas1);
            	cout<<"INGRESE EL PROTAGONISTA N°2: ";
            	fflush(stdin);
            	getline(cin,protagonistas2);
    		do{
		    	cout<<"\n***********************************"<<endl;
				cout<<"********* CALIFICACION ************"<<endl;
				cout<<"***********************************"<<endl;
				cout<<"  1. TODOS LOS PUBLICOS (TP)"<<endl;
				cout<<"  2. MAYORES DE 13 AÑOS (M13)"<<endl;
				cout<<"  3. MAYORES DE 18 AÑOS (M18)"<<endl;
				cout<<"***********************************"<<endl;
	    		cout<<"\nINGRESE LA CALIFICACION: ";
	    		cin>>opp;
			}while(opp<1 || opp>3);
			switch(opp){
				case 1:
					Calificacion= "TP";
			    	newPelicula=new(PELICULA);
        	    	newPelicula->pelicula=pelicula;
        	    	newPelicula->dia=dia;
        	    	newPelicula->hora=hora;
        	    	newPelicula->minutos=minutos;
        	    	newPelicula->protagonistas1=protagonistas1;
        	    	newPelicula->protagonistas2=protagonistas2;
        	    	newPelicula->Calificacion=Calificacion;
        	    	newPelicula->sgt=NULL;
        	    	newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		        		pcabPelicula=newPelicula;		
        	    	}else{
		                pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	    	    	}	
	        	    	pfinPelicula=newPelicula;
		        	break;
		    	case 2:
		    		Calificacion= "M13";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		            	pcabPelicula=newPelicula;		
            		}else{
		     	        pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	            	}	
	            	pfinPelicula=newPelicula;
		        	break;
		    	case 3:
		        	Calificacion= "M18";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
	    		    	pcabPelicula=newPelicula;		
            		}else{
	    		        pfinPelicula->sgt=newPelicula;
	    		        newPelicula->ant=pfinPelicula;
	     	       	}	
	    	        pfinPelicula=newPelicula;
		        	break;
	                }
			break;
			case 2:
			dia="Martes";
			do{
    	    	cout<<"INGRESE LA HORA: ";
    	        cin>>hora;
    	    }while(hora<1 || hora>24);
        	do{
    	    	cout<<"CON SUS MINUTOS: ";
    	        cin>>minutos;
        	}while(minutos<0 || minutos>59);
            	cout<<"INGRESE EL PROTAGONISTA N°1: ";
            	fflush(stdin);
            	getline(cin,protagonistas1);
            	cout<<"INGRESE EL PROTAGONISTA N°2: ";
            	fflush(stdin);
            	getline(cin,protagonistas2);
    		do{
		    	cout<<"\n***********************************"<<endl;
				cout<<"********* CALIFICACION ************"<<endl;
				cout<<"***********************************"<<endl;
				cout<<"  1. TODOS LOS PUBLICOS (TP)"<<endl;
				cout<<"  2. MAYORES DE 13 AÑOS (M13)"<<endl;
				cout<<"  3. MAYORES DE 18 AÑOS (M18)"<<endl;
				cout<<"***********************************"<<endl;
	    		cout<<"\nINGRESE LA CALIFICACION: ";
	    		cin>>opp;
			}while(opp<1 || opp>3);
			switch(opp){
				case 1:
					Calificacion= "TP";
			    	newPelicula=new(PELICULA);
        	    	newPelicula->pelicula=pelicula;
        	    	newPelicula->dia=dia;
        	    	newPelicula->hora=hora;
        	    	newPelicula->minutos=minutos;
        	    	newPelicula->protagonistas1=protagonistas1;
        	    	newPelicula->protagonistas2=protagonistas2;
        	    	newPelicula->Calificacion=Calificacion;
        	    	newPelicula->sgt=NULL;
        	    	newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		        		pcabPelicula=newPelicula;		
        	    	}else{
		                pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	    	    	}	
	        	    	pfinPelicula=newPelicula;
		        	break;
		    	case 2:
		    		Calificacion= "M13";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		            	pcabPelicula=newPelicula;		
            		}else{
		     	        pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	            	}	
	            	pfinPelicula=newPelicula;
		        	break;
		    	case 3:
		        	Calificacion= "M18";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
	    		    	pcabPelicula=newPelicula;		
            		}else{
	    		        pfinPelicula->sgt=newPelicula;
	    		        newPelicula->ant=pfinPelicula;
	     	       	}	
	    	        pfinPelicula=newPelicula;
		        	break;
	                }
			break;
			case 3:
			dia="Miercoles";
			do{
    	    	cout<<"INGRESE LA HORA: ";
    	        cin>>hora;
    	    }while(hora<1 || hora>24);
        	do{
    	    	cout<<"CON SUS MINUTOS: ";
    	        cin>>minutos;
        	}while(minutos<0 || minutos>59);
            	cout<<"INGRESE EL PROTAGONISTA N°1: ";
            	fflush(stdin);
            	getline(cin,protagonistas1);
            	cout<<"INGRESE EL PROTAGONISTA N°2: ";
            	fflush(stdin);
            	getline(cin,protagonistas2);
    		do{
		    	cout<<"\n***********************************"<<endl;
				cout<<"********* CALIFICACION ************"<<endl;
				cout<<"***********************************"<<endl;
				cout<<"  1. TODOS LOS PUBLICOS (TP)"<<endl;
				cout<<"  2. MAYORES DE 13 AÑOS (M13)"<<endl;
				cout<<"  3. MAYORES DE 18 AÑOS (M18)"<<endl;
				cout<<"***********************************"<<endl;
	    		cout<<"\nINGRESE LA CALIFICACION: ";
	    		cin>>opp;
			}while(opp<1 || opp>3);
			switch(opp){
				case 1:
					Calificacion= "TP";
			    	newPelicula=new(PELICULA);
        	    	newPelicula->pelicula=pelicula;
        	    	newPelicula->dia=dia;
        	    	newPelicula->hora=hora;
        	    	newPelicula->minutos=minutos;
        	    	newPelicula->protagonistas1=protagonistas1;
        	    	newPelicula->protagonistas2=protagonistas2;
        	    	newPelicula->Calificacion=Calificacion;
        	    	newPelicula->sgt=NULL;
        	    	newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		        		pcabPelicula=newPelicula;		
        	    	}else{
		                pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	    	    	}	
	        	    	pfinPelicula=newPelicula;
		        	break;
		    	case 2:
		    		Calificacion= "M13";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		            	pcabPelicula=newPelicula;		
            		}else{
		     	        pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	            	}	
	            	pfinPelicula=newPelicula;
		        	break;
		    	case 3:
		        	Calificacion= "M18";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
	    		    	pcabPelicula=newPelicula;		
            		}else{
	    		        pfinPelicula->sgt=newPelicula;
	    		        newPelicula->ant=pfinPelicula;
	     	       	}	
	    	        pfinPelicula=newPelicula;
		        	break;
	                }
			break;
			case 4:
			dia="Jueves";
			do{
    	    	cout<<"INGRESE LA HORA: ";
    	        cin>>hora;
    	    }while(hora<1 || hora>24);
        	do{
    	    	cout<<"CON SUS MINUTOS: ";
    	        cin>>minutos;
        	}while(minutos<0 || minutos>59);
            	cout<<"INGRESE EL PROTAGONISTA N°1: ";
            	fflush(stdin);
            	getline(cin,protagonistas1);
            	cout<<"INGRESE EL PROTAGONISTA N°2: ";
            	fflush(stdin);
            	getline(cin,protagonistas2);
    		do{
		    	cout<<"\n***********************************"<<endl;
				cout<<"********* CALIFICACION ************"<<endl;
				cout<<"***********************************"<<endl;
				cout<<"  1. TODOS LOS PUBLICOS (TP)"<<endl;
				cout<<"  2. MAYORES DE 13 AÑOS (M13)"<<endl;
				cout<<"  3. MAYORES DE 18 AÑOS (M18)"<<endl;
				cout<<"***********************************"<<endl;
	    		cout<<"\nINGRESE LA CALIFICACION: ";
	    		cin>>opp;
			}while(opp<1 || opp>3);
			switch(opp){
				case 1:
					Calificacion= "TP";
			    	newPelicula=new(PELICULA);
        	    	newPelicula->pelicula=pelicula;
        	    	newPelicula->dia=dia;
        	    	newPelicula->hora=hora;
        	    	newPelicula->minutos=minutos;
        	    	newPelicula->protagonistas1=protagonistas1;
        	    	newPelicula->protagonistas2=protagonistas2;
        	    	newPelicula->Calificacion=Calificacion;
        	    	newPelicula->sgt=NULL;
        	    	newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		        		pcabPelicula=newPelicula;		
        	    	}else{
		                pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	    	    	}	
	        	    	pfinPelicula=newPelicula;
		        	break;
		    	case 2:
		    		Calificacion= "M13";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		            	pcabPelicula=newPelicula;		
            		}else{
		     	        pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	            	}	
	            	pfinPelicula=newPelicula;
		        	break;
		    	case 3:
		        	Calificacion= "M18";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
	    		    	pcabPelicula=newPelicula;		
            		}else{
	    		        pfinPelicula->sgt=newPelicula;
	    		        newPelicula->ant=pfinPelicula;
	     	       	}	
	    	        pfinPelicula=newPelicula;
		        	break;
	                }
			break;
			case 5:
			dia="Viernes";
			do{
    	    	cout<<"INGRESE LA HORA: ";
    	        cin>>hora;
    	    }while(hora<1 || hora>24);
        	do{
    	    	cout<<"CON SUS MINUTOS: ";
    	        cin>>minutos;
        	}while(minutos<0 || minutos>59);
            	cout<<"INGRESE EL PROTAGONISTA N°1: ";
            	fflush(stdin);
            	getline(cin,protagonistas1);
            	cout<<"INGRESE EL PROTAGONISTA N°2: ";
            	fflush(stdin);
            	getline(cin,protagonistas2);
    		do{
		    	cout<<"\n***********************************"<<endl;
				cout<<"********* CALIFICACION ************"<<endl;
				cout<<"***********************************"<<endl;
				cout<<"  1. TODOS LOS PUBLICOS (TP)"<<endl;
				cout<<"  2. MAYORES DE 13 AÑOS (M13)"<<endl;
				cout<<"  3. MAYORES DE 18 AÑOS (M18)"<<endl;
				cout<<"***********************************"<<endl;
	    		cout<<"\nINGRESE LA CALIFICACION: ";
	    		cin>>opp;
			}while(opp<1 || opp>3);
			switch(opp){
				case 1:
					Calificacion= "TP";
			    	newPelicula=new(PELICULA);
        	    	newPelicula->pelicula=pelicula;
        	    	newPelicula->dia=dia;
        	    	newPelicula->hora=hora;
        	    	newPelicula->minutos=minutos;
        	    	newPelicula->protagonistas1=protagonistas1;
        	    	newPelicula->protagonistas2=protagonistas2;
        	    	newPelicula->Calificacion=Calificacion;
        	    	newPelicula->sgt=NULL;
        	    	newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		        		pcabPelicula=newPelicula;		
        	    	}else{
		                pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	    	    	}	
	        	    	pfinPelicula=newPelicula;
		        	break;
		    	case 2:
		    		Calificacion= "M13";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		            	pcabPelicula=newPelicula;		
            		}else{
		     	        pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	            	}	
	            	pfinPelicula=newPelicula;
		        	break;
		    	case 3:
		        	Calificacion= "M18";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
	    		    	pcabPelicula=newPelicula;		
            		}else{
	    		        pfinPelicula->sgt=newPelicula;
	    		        newPelicula->ant=pfinPelicula;
	     	       	}	
	    	        pfinPelicula=newPelicula;
		        	break;
	                }
			break;
			case 6:
			dia="Sabado";
			do{
    	    	cout<<"INGRESE LA HORA: ";
    	        cin>>hora;
    	    }while(hora<1 || hora>24);
        	do{
    	    	cout<<"CON SUS MINUTOS: ";
    	        cin>>minutos;
        	}while(minutos<0 || minutos>59);
            	cout<<"INGRESE EL PROTAGONISTA N°1: ";
            	fflush(stdin);
            	getline(cin,protagonistas1);
            	cout<<"INGRESE EL PROTAGONISTA N°2: ";
            	fflush(stdin);
            	getline(cin,protagonistas2);
    		do{
		    	cout<<"\n***********************************"<<endl;
				cout<<"********* CALIFICACION ************"<<endl;
				cout<<"***********************************"<<endl;
				cout<<"  1. TODOS LOS PUBLICOS (TP)"<<endl;
				cout<<"  2. MAYORES DE 13 AÑOS (M13)"<<endl;
				cout<<"  3. MAYORES DE 18 AÑOS (M18)"<<endl;
				cout<<"***********************************"<<endl;
	    		cout<<"\nINGRESE LA CALIFICACION: ";
	    		cin>>opp;
			}while(opp<1 || opp>3);
			switch(opp){
				case 1:
					Calificacion= "TP";
			    	newPelicula=new(PELICULA);
        	    	newPelicula->pelicula=pelicula;
        	    	newPelicula->dia=dia;
        	    	newPelicula->hora=hora;
        	    	newPelicula->minutos=minutos;
        	    	newPelicula->protagonistas1=protagonistas1;
        	    	newPelicula->protagonistas2=protagonistas2;
        	    	newPelicula->Calificacion=Calificacion;
        	    	newPelicula->sgt=NULL;
        	    	newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		        		pcabPelicula=newPelicula;		
        	    	}else{
		                pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	    	    	}	
	        	    	pfinPelicula=newPelicula;
		        	break;
		    	case 2:
		    		Calificacion= "M13";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		            	pcabPelicula=newPelicula;		
            		}else{
		     	        pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	            	}	
	            	pfinPelicula=newPelicula;
		        	break;
		    	case 3:
		        	Calificacion= "M18";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
	    		    	pcabPelicula=newPelicula;		
            		}else{
	    		        pfinPelicula->sgt=newPelicula;
	    		        newPelicula->ant=pfinPelicula;
	     	       	}	
	    	        pfinPelicula=newPelicula;
		        	break;
	                }
			break;
			case 7:
			dia="Domingo";
			do{
    	    	cout<<"INGRESE LA HORA: ";
    	        cin>>hora;
    	    }while(hora<1 || hora>24);
        	do{
    	    	cout<<"CON SUS MINUTOS: ";
    	        cin>>minutos;
        	}while(minutos<0 || minutos>59);
            	cout<<"INGRESE EL PROTAGONISTA N°1: ";
            	fflush(stdin);
            	getline(cin,protagonistas1);
            	cout<<"INGRESE EL PROTAGONISTA N°2: ";
            	fflush(stdin);
            	getline(cin,protagonistas2);
    		do{
		    	cout<<"\n***********************************"<<endl;
				cout<<"********* CALIFICACION ************"<<endl;
				cout<<"***********************************"<<endl;
				cout<<"  1. TODOS LOS PUBLICOS (TP)"<<endl;
				cout<<"  2. MAYORES DE 13 AÑOS (M13)"<<endl;
				cout<<"  3. MAYORES DE 18 AÑOS (M18)"<<endl;
				cout<<"***********************************"<<endl;
	    		cout<<"\nINGRESE LA CALIFICACION: ";
	    		cin>>opp;
			}while(opp<1 || opp>3);
			switch(opp){
				case 1:
					Calificacion= "TP";
			    	newPelicula=new(PELICULA);
        	    	newPelicula->pelicula=pelicula;
        	    	newPelicula->dia=dia;
        	    	newPelicula->hora=hora;
        	    	newPelicula->minutos=minutos;
        	    	newPelicula->protagonistas1=protagonistas1;
        	    	newPelicula->protagonistas2=protagonistas2;
        	    	newPelicula->Calificacion=Calificacion;
        	    	newPelicula->sgt=NULL;
        	    	newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		        		pcabPelicula=newPelicula;		
        	    	}else{
		                pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	    	    	}	
	        	    	pfinPelicula=newPelicula;
		        	break;
		    	case 2:
		    		Calificacion= "M13";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
		            	pcabPelicula=newPelicula;		
            		}else{
		     	        pfinPelicula->sgt=newPelicula;
		                newPelicula->ant=pfinPelicula;
	            	}	
	            	pfinPelicula=newPelicula;
		        	break;
		    	case 3:
		        	Calificacion= "M18";
            		newPelicula=new(PELICULA);
            		newPelicula->pelicula=pelicula;
            		newPelicula->dia=dia;
            		newPelicula->hora=hora;
            		newPelicula->minutos=minutos;
            		newPelicula->protagonistas1=protagonistas1;
            		newPelicula->protagonistas2=protagonistas2;
            		newPelicula->Calificacion=Calificacion;
            		newPelicula->sgt=NULL;
            		newPelicula->ant=NULL;	
            		if(pcabPelicula==NULL){
	    		    	pcabPelicula=newPelicula;		
            		}else{
	    		        pfinPelicula->sgt=newPelicula;
	    		        newPelicula->ant=pfinPelicula;
	     	       	}	
	    	        pfinPelicula=newPelicula;
		        	break;
	                }
			break;	
    }
}


void MOSTARSESIONES(SESIONES *pcabSesiones){
	SESIONES *Buscar=pcabSesiones;
	while(Buscar!=NULL){
		cout<<" #*" <<Buscar->NSecciones<<endl;
		Buscar=Buscar->sgt;
	}
}

void registrosesion(SESIONES *&pcabSesiones,SESIONES *&pfinSesiones,int sesion){
	SESIONES *newSesiones;
 	
	newSesiones=new(SESIONES);
 	newSesiones->NSecciones=sesion;
 	newSesiones->pcabPelicula=NULL;
 	newSesiones->pfinPelicula=NULL;
 	newSesiones->sgt=NULL;
 	newSesiones->ant=NULL;
 	
 	if(pcabSesiones==NULL){
 		pcabSesiones=newSesiones;
	}else{
	   	pfinSesiones->sgt=newSesiones;
	   	newSesiones->ant=pfinSesiones;	
	}
 	pfinSesiones=newSesiones;	
}

SESIONES *buscarsesion(SESIONES *pcabSesiones,int sesion){
	SESIONES *SesionesA=pcabSesiones;
    while(SesionesA!=NULL){
 		if(SesionesA->NSecciones==sesion){
 		   return SesionesA;
		}
		SesionesA=SesionesA->sgt ;
	 }
	return NULL;
}

SALAS *buscarsala(SALAS *pcabSala,int sala){
	SALAS *nodoAct=pcabSala;
	while(nodoAct!=NULL){
		if(nodoAct->NSala==sala){
		return nodoAct;
	}
	nodoAct=nodoAct->sgt;
	}
	return NULL;	
}

void registrosalas(SALAS *&pcabSala,SALAS *&pfinSala,int sala){
	SALAS *newsala;
	newsala=new(SALAS);
	newsala->NSala=sala;
	newsala->pcabSesiones=NULL;
 	newsala->pfinSesiones=NULL;
 	newsala->sgt =NULL;
 	newsala->ant =NULL;
 	if(pcabSala==NULL){
 		pcabSala=newsala;
	}else{
	   	pfinSala->sgt =newsala;
	   	newsala->ant =pfinSala;	
	}
 	pfinSala=newsala;
}

void MOSTARSALAS(SALAS *pcabSala){
	SALAS *Buscar=pcabSala;
	while(Buscar!=NULL){
		cout<<" #*" <<Buscar->NSala<<endl;
		Buscar=Buscar->sgt;
	}
}

void MOSTARCINE(CINE *pcab){
	int n=1;
	CINE *mostrar=pcab;
	while(mostrar!=NULL){
		cout<<" N°"<<n<<": "<<mostrar->Cine<<endl;
		mostrar=mostrar->siguiente;
		n++;
	}
}

CINE *buscarCINE(CINE *pcab,string cines){
	CINE *nodoAct=pcab;
	while(nodoAct!=NULL){
		if(nodoAct->Cine==cines){
		return nodoAct;
	}
	nodoAct=nodoAct->siguiente;
	}
	return NULL;	
}

void registrocines(CINE *&pcab,CINE *&pfin,string cines){
	CINE *newcine;
	newcine=new(CINE);
	newcine->Cine=cines;
	newcine->pcabSala=NULL;
	newcine->pfinSala=NULL;
	newcine->siguiente=NULL;
	newcine->anterior=NULL;
	if(pcab==NULL){
		pcab=newcine;
	}else{
		pfin->siguiente=newcine;
		newcine->anterior=pfin;
	}
	pfin=newcine;
	//registrodias(pcab,pfin);
}

void registrociness(CINE *&pcab,CINE *&pfin){
	string cine1,cine2,cine3;
    CINE *newcine;
    cine1="Cinemark";
	newcine=new(CINE);
	newcine->Cine=cine1;
	newcine->pcabSala=NULL;
	newcine->pfinSala=NULL;
	newcine->siguiente=NULL;
	newcine->anterior=NULL;
	if(pcab==NULL){
		pcab=newcine;
	}else{
		pfin->siguiente=newcine;
		newcine->anterior=pfin;
	}
	pfin=newcine;
	
	cine2="Multicines";
	newcine=new(CINE);
	newcine->Cine=cine2;
	newcine->pcabSala=NULL;
	newcine->pfinSala=NULL;
	newcine->siguiente=NULL;
	newcine->anterior=NULL;
	if(pcab==NULL){
		pcab=newcine;
	}else{
		pfin->siguiente=newcine;
		newcine->anterior=pfin;
	}
	pfin=newcine;
	
	cine3="Supercines";
	newcine=new(CINE);
	newcine->Cine=cine3;
	newcine->pcabSala=NULL;
	newcine->pfinSala=NULL;
	newcine->siguiente=NULL;
	newcine->anterior=NULL;
	if(pcab==NULL){
		pcab=newcine;
	}else{
		pfin->siguiente=newcine;
		newcine->anterior=pfin;
	}
	pfin=newcine;
}

int menu(){
	int op;
	do{
		cout<<"\n\t\t *** MENU *** \n";
        cout<<" 1. REGISTRAR CINES\n";
    	cout<<" 2. REGISTRAR SALAS\n";
    	cout<<" 3. REGISTRAR SESIONES\n";
    	cout<<" 4. REGISTRAR PELICULA\n";
    	cout<<" 5. VISUALIZAR INFORMACION EN UNA SALA CONCRETA\n";
    	cout<<" 6. BUSCAR PELICULA\n";
    	cout<<" 7. MODIFICAR UNA PELICULA DE UNA SALA CONCRETA\n";
    	cout<<" 8. LISTAR PELICULAS POR EDADES\n";
    	cout<<" 9. LISTAR CARTELERA DE TODAS LAS EMPRESAS ASOCIADAS\n";
    	cout<<" 10. SALIR DEL PROGRAMA\n";
        cout<<endl<<"ELIJA LA OPERACION: ";
    	cin>>op;
    	cin.get();
	}while(op<1 || op>10);
	return op;
}

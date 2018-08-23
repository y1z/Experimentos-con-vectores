#include "CronometroGeneral.h"

// contructor por defecto . 
Cronometro::Cronometro(){}

// contructor sobrecargado valores [mc] [ms] [s]
Cronometro::Cronometro(std::string Indicador)
{
	if( Indicador == "mc"){
		M_TipoTiempo = Macrosegundos; 
	}
	else if (Indicador == "ms") {
		M_TipoTiempo = Milisegundos;
	}
	else if(Indicador == "s"){
		M_TipoTiempo = Segundo;
	}
	else if (Indicador == "auto" || Indicador == "Auto") {
		M_TipoTiempo = AUTO;
		ComenzarMedirTiempo();
	}
	else {
		std::cout << "error no reconosco la medicion de timepo que me indicaste\n El tiempo se presentara de la forma por defecto de presentacion. \n preciona enter";
		std::cin.ignore();
		std::cin.get();
	}

}

// destructor por defecto .
Cronometro::~Cronometro() {
	if (M_TipoTiempo == AUTO) 
	{
		M_Fin = ::high_resolution_clock::now();
		M_ResultadoPorDefecto = M_Fin - M_Inicio;
		std::cout << "El Timepo Fue " << M_ResultadoPorDefecto.count() << " s";
	}
}

// para Iniciar el conteo del timepo 
void Cronometro::ComenzarMedirTiempo()
{
	M_Inicio = ::high_resolution_clock::now();//<= consigo el timepo del inicio 
}

// para Finaliza el conteo del tiempo 
void Cronometro::FinalizarMedirTiempo() 
{
	
	M_Fin = ::high_resolution_clock::now();//<= consigo el timepo final 
	M_ResultadoPorDefecto = M_Fin - M_Inicio;//<= el resultado 


	switch (M_TipoTiempo)
	{
	case(Defecto): 
			PrintResultado();
		break;

	case(Segundo):
		M_Segundos = std::chrono::duration_cast<std::chrono::seconds>(M_ResultadoPorDefecto);
		PrintResultado();
		break;

	case(Milisegundos):
		M_miliSegundos = std::chrono::duration_cast<std::chrono::milliseconds>(M_ResultadoPorDefecto);
		PrintResultado();
		break;

	case(Macrosegundos):
		M_macroSegundos = std::chrono::duration_cast<std::chrono::microseconds>(M_ResultadoPorDefecto);
		PrintResultado();
		break;

	default:
		break;
	}

}

// para ense�ar el resultado .
void Cronometro::PrintResultado() {

	// lo que hace este switch case es determinar cual Unidad de timepo presentar al usuario y imprimirlo en la consola.
	switch (M_TipoTiempo)
	{
	case(Defecto):
		std::cout << "El Timepo fue " << M_ResultadoPorDefecto.count() << "s\n";
		break;
	case(Segundo):
		if (M_Segundos.count() == 1) 
		{
			std::cout << "El Timepo fue " << M_Segundos.count() << " Segundo\n";
		}
		else
		{
			std::cout << "El Timepo fue " << M_Segundos.count() << " Segundos\n";
		}
		break;
	case(Milisegundos):
		std::cout <<"El Tiempo fue "<< M_miliSegundos.count()<<" ms\n";
		break;
	case(Macrosegundos):

		if (M_macroSegundos.count() == 1)
		{
			std::cout << "El Tiempo fue " << M_macroSegundos.count() << " MacroSegundo";
		}
		else
		{
			std::cout << "El Tiempo fue " << M_macroSegundos.count() << " MacroSegundos";
		}
		break;
	default:
		std::cout << "El Timepo fue " << M_ResultadoPorDefecto.count() << " s";
		break;
	}
}

void Cronometro::ElegirMedidaTiempo(std::string Indicador) {
	if (Indicador == "mc") {
		M_TipoTiempo = Macrosegundos;
	}
	else if (Indicador == "ms") {
		M_TipoTiempo = Milisegundos;
	}
	else if (Indicador == "s") {
		M_TipoTiempo = Segundo;
	}
	else {
		std::cout << "error no reconosco la medicion de timepo que me indicaste\n El tiempo se presentara de la forma por defecto de presentacion. \n preciona enter";
		std::cin.ignore();
		std::cin.get();
	}


}
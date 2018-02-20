#ifndef HLINE_H
#define HLINE_H

class hline { // provides health lines
	private:
		int mem[46];
		
	public:
		void assign(int nu,, ... ) // The "assign" function handles the int-array's values. The param function is not restricted to any number of parameters, yet here it won't work right for other than 46 parameters (plus "Anzahl").
		{
			va_list params; // Zugriffshandle für Parameter
			int intpar;	 // Parameterinhalt
			va_start(params, num); // Zugriff vorbereiten
			// Durchlaufe alle (Anzahl num) Parameter 
			for (int i=0; i<num; i++)
			{
				intpar = va_arg(params, int); // hole den Parameter
				mem[i] = intpar;
			}
			va_end(params); // Zugriff abschließen
		}
		
		int get(int age) {
			return mem[age-50];
		}

};

#endif // HLINE_H
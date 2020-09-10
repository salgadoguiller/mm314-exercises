#include <iostream>

using namespace std;

int main()
{
    int planilla = 0;
    int pago_por_hora;
    int horas_extras_multiplicador;
    int horas_trabajadas;
    int sueldo_empleado;
    string mas_empleados = "Si";
    string turno;

    while (mas_empleados == "Si") {
        cout << "Ingrese el turno (A, B):" << endl;
        cin >> turno;

        if (turno != "A" && turno != "B") {
            cout << "El turno debe ser A o B" << endl;
        } else {
            if (turno == "A"){
                pago_por_hora = 70;
                horas_extras_multiplicador = 2;
            }

            if (turno == "B"){
                pago_por_hora = 90;
                horas_extras_multiplicador = 3;
            }

            cout << "Ingrese el numero de horas trabajadas:" << endl;
            cin >> horas_trabajadas;

            if (horas_trabajadas < 0) {
                cout << "El numero de horas trabajadas debe ser mayor o igual a 0" << endl;
            } else {
                if (horas_trabajadas <= 40) {
                    sueldo_empleado = horas_trabajadas*pago_por_hora;
                } else {
                    sueldo_empleado = (40*pago_por_hora) + ((horas_trabajadas-40)*pago_por_hora*horas_extras_multiplicador);
                }

                cout << "El sueldo del empleado es: " << sueldo_empleado << endl;
                planilla = planilla+sueldo_empleado;
            }
        }

        cout << "Desea procesar otro empleado? Si/No" << endl;
        cin >> mas_empleados;
    }

    cout << "El total de la planilla es: " << planilla << endl;

    return 0;
}

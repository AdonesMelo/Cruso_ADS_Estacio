package ex005;

import java.util.Calendar;

public class Data {
    private int dia;
    private int mes;
    private int ano;

    public Data(int dia, int mes, int ano) {
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    // Converte para Calendar (útil para Pessoa)
    public Calendar toCalendar() {
        Calendar c = Calendar.getInstance();
        c.set(ano, mes - 1, dia); // mês começa em 0
        return c;
    }

    // Exibir a data formatada
    public String getDataFormatada() {
        return String.format("%02d/%02d/%04d", dia, mes, ano);
    }

    // Getters
    public int getDia() { return dia; }
    public int getMes() { return mes; }
    public int getAno() { return ano; }
}

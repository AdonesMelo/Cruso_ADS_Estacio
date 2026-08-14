package ex002;

import java.util.Comparator;

public class ComparaPessoa implements Comparator<PessoaFisica> {
    @Override
    public int compare(PessoaFisica obj1, PessoaFisica obj2) {
        return obj1.getNome().compareToIgnoreCase(obj2.getNome());
    }
}
//package simpleGav1;

public class Individuo {

  // Datos
  private static final int numGenesPorDefecto = 64;
  // NOTA: En Indviduo se almacenan bytes, no se puede cambiar
  private byte[] genes = new byte[numGenesPorDefecto];

  // Para aumentar eficiencia
  private double fitness = 0;

  // Constructor
  public Individuo () {
  }

  // Numero de genes
  public int numGenes() {
    return genes.length;
  }

  // Obtener el gen de una posicion concreta
  public byte getGen(int indice) {
    return genes[indice];
  }

  // Informar el gen de una posicion concreta
  public void setGen(int indice, byte valor) {
    genes[indice] = valor;
    fitness = 0;
  }

  // Informar el gen de una posicion concreta con un valor random
  public void setGenRandom(int indice) {
    byte gen = (byte) Math.round(Math.random());
    setGen(indice,gen);
  }


  // Inicializar individuo con valores random
  public void inicializaIndividuo() {
    for (int i = 0; i < numGenes(); i++) {
      setGenRandom(i);
    }
  }

  // String con la informacion del individuo
  public String toString() {
    String genString = "";
    for (int i = 0; i < numGenes(); i++) {
      genString += getGen(i);
    }
    return genString;
  }

  /////////////////////////////////////
  // Metodos especificos del genetico
  /////////////////////////////////////

  // Fitness
  // NOTA: PONER UN PARAMETRO CalculoFitness OBLIGA A UNA DE ESTAS OPCIONES:
  // NOTA: - IR PASANDO EL PARAMETRO ENTRE CLASES 
  // NOTA: - CREAR UNA VARIABLE DE CLASE EN Poblacion
  // NOTA: UNA ALTERNATIVA SERIA DEFINIR CalculoFitness COMO CLASE ESTATICA
  public double fitnessIndividuo(CalculoFitness calculoFitness) {
    if (fitness == 0) {
      fitness = calculoFitness.fitnessIndividuo(this);
    }
    return fitness;
  }

  // Recombinacion
  // NOTA: ALTERNATIVA - recombinar en funcion del fitness
  public Individuo recombinaIndividuos(Individuo indv, double umbralRecombinacion) {
    Individuo nuevoIndv = new Individuo();

    for (int i = 0; i < numGenes(); i++) {
      if (Math.random() <= umbralRecombinacion) {
        nuevoIndv.setGen(i,this.getGen(i));
      } else {
        nuevoIndv.setGen(i,indv.getGen(i));
      }
    }
    return nuevoIndv;
  }

  // Mutacion
  // NOTA: ALTERNATIVA - mutar en funcion del fitness
  public void mutaIndividuo(double tasaMutacion) {
    for (int i = 0; i < numGenes(); i++) {
      if (Math.random() <= tasaMutacion) {
        // Crear gen al azar
        setGenRandom(i);
      }
    }
  }

}

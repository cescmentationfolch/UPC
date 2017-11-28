//package simpleGav1;

public class CalculoFitness {

  // Datos
  private Individuo solucion;

  // Creacion de la solucion
  public void defineSolucionRandom() {
    solucion = new Individuo();
    solucion.inicializaIndividuo();
  }

  // String con la solucion
  public String stringSolucion() {
    return solucion.toString();
  }

  // Maxima fitness posible
  public double maxFitness() {
    return (double)solucion.numGenes();
  }

  // Calculo de la fitness para un individuo
  public double fitnessIndividuo(Individuo individuo) {
    int fitness = 0;   
    for (int i = 0; i < individuo.numGenes() && i < solucion.numGenes(); i++) {
      // NOTA: Con byte funciona, pero con otros tipos/clases puede no funcionar
      if (individuo.getGen(i) == solucion.getGen(i)) {
        fitness++;
      }
    }
    return (double)fitness;
  }
}


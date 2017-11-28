//package simpleGav1;

public class GA {

  private static final int maxGeneraciones = 1000;
  private static final int nIndividuosPoblacion = 50;

  private static final boolean elitismo = true;
  private static final int numTorneos = 5;
  private static final double umbralRecombinacion = 0.5;
  private static final double tasaMutacion = 0.015;

  public void algoritmoGenetico() {
    CalculoFitness calculoFitness = new CalculoFitness();

    // Solucion
    calculoFitness.defineSolucionRandom();

    // Crear poblacion inicial
    Poblacion poblacion = new Poblacion(nIndividuosPoblacion,true);
        
    // Evolucionar la poblacion hasta conseguir encontrar el mas adaptado
    int generacion = 0;
    while (generacion < maxGeneraciones &&
           poblacion.individuoMasApto(calculoFitness).fitnessIndividuo(calculoFitness) < calculoFitness.maxFitness()) {
      System.out.println("Generacion: " + generacion +
                         " Fittest: " + poblacion.individuoMasApto(calculoFitness).fitnessIndividuo(calculoFitness));
      poblacion = poblacion.evolucionaPoblacion(calculoFitness,elitismo,numTorneos,umbralRecombinacion,tasaMutacion);
      generacion++;
    }
    System.out.println("Generacion: " + generacion +
                       " Fittest: " + poblacion.individuoMasApto(calculoFitness).fitnessIndividuo(calculoFitness));

    // Resultados
    System.out.println("Genes de la solucion:");
    System.out.println(calculoFitness.stringSolucion());
    System.out.println("Genes del mejor individuo encontrado en la generacion " + generacion + ":");
    System.out.println(poblacion.individuoMasApto(calculoFitness).toString());
    double diferencia = calculoFitness.maxFitness() - poblacion.individuoMasApto(calculoFitness).fitnessIndividuo(calculoFitness);
    System.out.println("Diferencia de fitness con respecto a la solucion real: " + diferencia);
  }

}

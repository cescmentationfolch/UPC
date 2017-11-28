//package simpleGav1;

public class Poblacion {

  // Datos
  private Individuo[] individuos;

  // Constructor
  public Poblacion(int tamanyo, boolean inicializa) {
    individuos = new Individuo[tamanyo];
    // Inicializa la poblacion
    if (inicializa) {
      for (int i = 0; i < numIndividuos(); i++) {
        Individuo nuevoIndv = new Individuo();
        nuevoIndv.inicializaIndividuo();
        setIndividuo(i,nuevoIndv);
      }
    }
  }

  // Numero de individuos
  public int numIndividuos() {
    return individuos.length;
  }

  // Obtener el individuo de una posicion concreta
  public Individuo getIndividuo(int indice) {
    return individuos[indice];
  }

  // Informar el individuo de una posicion concreta
  public void setIndividuo(int indice, Individuo indv) {
    individuos[indice] = indv;
  }

  /////////////////////////////////////
  // Metodos especificos del genetico
  /////////////////////////////////////

  // Individuo mas apto
  public Individuo individuoMasApto(CalculoFitness calculoFitness) {
    Individuo fittest = individuos[0];
    for (int i = 0; i < numIndividuos(); i++) {
      if (fittest.fitnessIndividuo(calculoFitness) <=
            getIndividuo(i).fitnessIndividuo(calculoFitness)) {
        fittest = getIndividuo(i);
      }
    }
    return fittest;
  }

  // Seleccion de un individuo (para recombinacion)
  // NOTA: ALTERNATIVA - seleccion completamente random
  public Individuo seleccionaIndividuo(CalculoFitness calculoFitness, int numTorneos) {
    Poblacion torneo = new Poblacion(numTorneos,false);

    // Seleccion random de numTorneos individuos
    for (int i = 0; i < numTorneos; i++) {
      int randomId = (int) (Math.random() * numIndividuos());
      torneo.setIndividuo(i,getIndividuo(randomId));
    }
    // Obtiene el mas apto de los seleccionados
    Individuo fittest = torneo.individuoMasApto(calculoFitness);
    return fittest;
  }

  // Evolucion de una poblacion
  public Poblacion evolucionaPoblacion(CalculoFitness calculoFitness, boolean elitismo, int numTorneos, double umbralRecombinacion, double tasaMutacion) {
    Poblacion nuevaPoblacion = new Poblacion(numIndividuos(),false);

    // Guarda el mejor individuo
    int indiceMejor;
    if (elitismo) {
      nuevaPoblacion.setIndividuo(0,individuoMasApto(calculoFitness));
      indiceMejor = 1;
    } else {
      indiceMejor = 0;
    }

    // Recombinacion
    for (int i = indiceMejor; i < numIndividuos(); i++) {
      Individuo indv1 = seleccionaIndividuo(calculoFitness,numTorneos);
      Individuo indv2 = seleccionaIndividuo(calculoFitness,numTorneos);
      Individuo nuevoIndv = indv1.recombinaIndividuos(indv2,umbralRecombinacion);
      nuevaPoblacion.setIndividuo(i,nuevoIndv);
    }

    // Mutacion
    for (int i = indiceMejor; i < nuevaPoblacion.numIndividuos(); i++) {
      nuevaPoblacion.getIndividuo(i).mutaIndividuo(tasaMutacion);
    }

    return nuevaPoblacion;
  }

}

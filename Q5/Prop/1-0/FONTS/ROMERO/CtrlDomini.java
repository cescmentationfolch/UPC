package ROMERO;

import ROMERO.StubPartida;
import ROMERO.StubRanquing;

public class CtrlDomini {

	/* Atributs */
	private int nForats;
	private StubPartida partidaActual;
	private StubRanquing ranquing;

	/* Constructor */
	public CtrlDomini(){
		/**Baixa a la capa de persistencia per a recuperar
		el ranquing. En aquesta primera versio, per 
		testejar, la constructora crea un ranquing nou
		*/
		ranquing = new StubRanquing();
	}

	/**
	 * Funcions que es criden des del controlador
	 * de presentacio
	*/
	
	public void creaPartida(String nom, String rol, String dificultat, int nForats, int nColors, int nBolesColor, int nTorns) {
		partidaActual = new StubPartida(nom,rol,dificultat,nForats,nColors,nBolesColor,nTorns);
		this.nForats = nForats;
	}

	public boolean esDesada() {
		return partidaActual.esDesada();
	}

	public void desaPartida() {
		/** Baixa al controlador de persistencia per desar
		 * la partida
		 */
	}
	
	public void setCodiInicial(int[] codi) {
		partidaActual.setCodiInicial(codi);
	}
	
	public boolean comprovaBN(int B, int N) {
		int tornActual = partidaActual.getTornActual();
		int[] codiInicial = partidaActual.getCodiInicial();
		int[] candidat = partidaActual.getCandidat(tornActual);
		
		int negres = 0;
		for (int i = 0; i < nForats; i++) {
			if (codiInicial[i] == candidat[i]) {
				negres++;
				codiInicial[i] = -1;
			}
		}
        
		if (negres != N) return false;
		
		int blanques = 0;
		for (int i = 0; i < nForats; i++) {
			for (int j = 0; j < nForats; j++) {
				if (candidat[i] == codiInicial[j] && i != j) {
					blanques++;
					codiInicial[j] = -1;
					break;
				}
			}
		}
		
		if (blanques != B) return false;
		return true;
	}
	
	public void creaCandidat(int[] candidat) {
		partidaActual.creaCandidat(candidat);
	}
	
	public String[][] getRanquing(String Dificultat) {
		return ranquing.getRanquing(Dificultat);
	}
	
	public boolean afegeixNom(String nom, int torns, String dificultat) {
                return ranquing.afegeixNom(nom,torns,dificultat);
	}
	
	public String getRol() {
		return partidaActual.getRol();
	}
	
	public String getNom() {
		return partidaActual.getNom();
	}
	
	public void recuperapartidaActual(){
		/** Baixa al controlador de persistencia per recuperar
		 * la partidaActual desada
		 */
	}
	
	public int[] getCodiInicial() {
		return partidaActual.getCodiInicial();
	}
	
	public int getNForats() {
		return partidaActual.getNForats();
	}
	
	public int getNColors() {
		return partidaActual.getNColors();
	}
	
	public int getNBolesColor() {
		return partidaActual.getNBolesColor();
	}
	
	public int getNTorns() {
		return partidaActual.getNTorns();
	}
	
	public int getTornActual() {
		return partidaActual.getTornActual();
	}
	
	public int[] getCandidat(int i) {
		return partidaActual.getCandidat(i);
	}
	
	public void triaCodiInicialMaquina() {
		partidaActual.triaCodiInicialMaquina();
	}
	
	public void triaCandidatMaquina() {
		partidaActual.triaCandidatMaquina();
	}
	
	public boolean haGuanyat() {
        int tornActual = partidaActual.getTornActual(); 
		int[] codiInicial = partidaActual.getCodiInicial();
		int[] candidat = partidaActual.getCandidat(tornActual);
		
		for (int i = 0; i < nForats; i++) {
			if (codiInicial[i] != candidat[i]) return false;
		}
		
		return true;
	}
	
	public boolean haPerdut() {
		if (partidaActual.getTornActual() == partidaActual.getNTorns()) return true;
		return false;
	}
}

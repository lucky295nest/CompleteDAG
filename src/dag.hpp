#ifndef DAG_HPP
#define DAG_HPP

#include <string>
#include <vector>

typedef struct {
	int point_a;
	int point_b;
} dir;

/**
 * @brief   			Reprezentuje orientovaný acyklický graf (DAG)
 * @details 			Načte graf ze souboru a vytvoří kompletní DAG
 * 								na čež vypíše požadované hodnoty do terminálu
 * 								obsahuje i funkci pro zápis do souboru ve stejném formátu,
 * 								jako je jeho zadání.
 * @return 				Kompletní DAG
 */
class DAG {
private:
	/**
	 * @brief 			vektor obsahující vrcholy grafu
	 */
	std::vector<int> points;
	/**
	 * @brief 			vektor obsahující hrany grafu
	 */
	std::vector<dir> edges;

	/**
	 * @brief 			počet vrcholů před vytvořením kompletního DAG.
	 */
	int preCompletePointCount = 0;
	/**
	 * @brief 			počet hran před vytvořením kompletního DAG.
	 */
	int preCompleteEdgeCount = 0;
	/**
	 * @brief 			počet bodů po vytvoření kompletního DAG.
	 */
	int pointCount = 0;
	/**
	 * @brief 			počet hran po vytvoření kompletního DAG.
	 */
	int edgeCount = 0;
	/**
	 * @brief 			Boolean značící jestli jde o DAG nebo ne.
	 */
	bool isDAG = 0;

	/**
	 * @brief 			Funkce která vytvoří nový bod pokud ještě neexistuje.
	 */
	bool setPoint(int pnt);
	/**
	 * @brief 			Funkce která vytvoří novou hranu pokud ještě neexistuje.
	 * @details 		Tím se myslí že pokud existuje 0 -> 1 a parametry budou 1 -> 0
	 * 							tak se hrana nevytvoří.
	 */
	bool setEdge(int pnt_a, int pnt_b);
	/**
	 * @brief 	  	Funkce která z grafu vytvoří kompletní DAG.
	 * @details 		Doplní maximální počet hran bez vytvoření cyklu.
	 * 							Používá Kahnův algoritmus pro topologické řazení.
	 * 							Výsledek nemusí být jednoznačný pokud existují vrcholy bez vzájemné závislosti.
	 * 							Graf není DAG pokud počet seřazených prvků není roven počtu vrcholů.
	 * @return 			přetvoří sebe sama na kompletní DAG.
	 */
	void getComplete();

public:
	/**
	 * @brief 			Konstruktor načítající graf ze souboru
	 * @details 		Načte hrany ze souboru ve formátu "a b" na každém řádku.
	 *          		Využívá funkce setPoint, setEdge a getComplete.
	 * @param 			file_name Cesta ke vstupnímu souboru
	 */
	DAG(std::string file_name);

	/**
	 * @brief 			Vrátí počet vrcholů vstupního grafu
	 * @return 			Počet vrcholů před vytvořením kompletního DAG
	 */
	int getPrevPointCount() const;

	/**
	 * @brief 			Vrátí počet hran vstupního grafu
	 * @return 			Počet hran před vytvořením kompletního DAG
	 */
	int getPrevEdgeCount() const;

	/**
	 * @brief 			Vrátí počet vrcholů kompletního DAG
	 * @return 			Počet vrcholů po vytvoření kompletního DAG
	 */
	int getPointCount() const;

	/**
	 * @brief 			Vrátí počet hran kompletního DAG
	 * @return 			Počet hran po vytvoření kompletního DAG
	 */
	int getEdgeCount() const;

	/**
	 * @brief 			Zapíše hrany kompletního DAG do souboru
	 * @details 		Výstupní soubor má stejný formát jako vstupní soubor,
	 *          		tedy každá hrana je zapsána jako "a b" na samostatném řádku.
	 * @param 			file_name Cesta k výstupnímu souboru
	 */
	void printEdgesToFile(std::string file_name);

	/**
	 * @brief
	 * Operátor výstupu pro výpis informací o grafu
	 * @param  			os Výstupní proud
	 * @param  			d Instance DAG
	 * @return 			Výstupní proud s informacemi o grafu
	 */
	friend std::ostream &operator<<(std::ostream &os, const DAG &d);
};

#endif

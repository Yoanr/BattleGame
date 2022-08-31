# BattleGame

How to build:

- mkdir build
- cmake ..
- make

How to run:
- ./battleGame



Project:

/**
	 * Gère le passe d'un tour dans un petit jeu de bataille entre armée
	 *
	 * Dans ce jeu, deux camps s'affrontent : le camp 0 et le camp 1
	 *
	 * Les règles du jeu sont les suivantes :
	 *
	 * - Chacun des camps possède un certain nombre d'armées, positionnées sur
	 * un damier et repérées par leurs coordonnées x et y. Chaque armée possède
	 * une certaine valeur de force
	 *
	 * - Le jeu se joue en plusieurs tours. A chaque tour, chaque camp peut
	 * déplacer chacune de ses armées. Tous les déplacements ont lieu
	 * simultanément
	 *
	 * - Les armées peuvent se déplacer d'une seule case par tour, dans toutes
	 * les directions (diagonales comprises)
	 *
	 * - Si, à l'issue des déplacements, il y a plusieurs armées de camps
	 * différents sur une même case, un combat a lieu. On additionne alors les
	 * forces en présence sur la case pour chacun des camp. Les armées
	 * appartenant au camp ayant alors le moins de forces sur la case sont alors
	 * détruites. En cas d'égalité des forces, par convention, c'est toujours le
	 * camp 0 qui gagne.
	 *
	 * Cette méthode permet, connaissant la position des armées et les ordres de
	 * déplacement, d'effectuer l'application des règles du jeu afin de passer
	 * au tour suivant.
	 *
	 * Exemple :
	 *
	 * Supposons que le camp 0 possède deux armées, une armée d'ID 0 en (x = 2,
	 * y = 2) et de force 2, et une autre armée d'ID 1 en (2,3) de force 1.
	 *
	 * Supposons que le camp 1 possède une armée, d'ID 2 en (4,3) de force 2.
	 *
	 * Supposons que les ordres de déplacement soient les suivants :
	 * * - Armée 0 se déplace en 4, 2
     * * - Armée 1 se déplace en 3, 3
     * * - Armée 2 se déplace en 3, 3
     * Alors, notre script de passage devra générer un nouveau état du monde
     * pour le tour suivant qui sera le suivant : Le camp 0 possède une armée* d'ID 0 en (2, 2) de 
     * force 2, et le camp 1 possède une armée d'ID 2 en (3,3) de force 2. 
     * En effet, l'ordre de l'armée 0 était incorrect (les armées ne peuvent se déplacer que vers une 
     * case adjacente) : l'armée ne se déplace donc pas. 
     * Par ailleurs, les armées 1 et 2 se sont toutes deux déplacées vers la même case et, étant 
     * de camp différent, elles ont donc engagé le combat. 
     * L'armée 1 ayant une force inférieure, elle a été détruite.
	 *
	 * @param etatPrecedent Contient l'état du monde au début du tour. Cette
	 *        méthode ne doit pas modifier directement cet objet.
	 * @param ordres La liste des ordres de déplacement
	 * @return le nouvel état du monde après le passage de ce tour.
	 */
	virtual EtatMonde *effetueTour(EtatMonde *etatPrecedent, std::vector<OrdreArmee*> &ordres) = 0;

#ifndef _MATERIALES_H_
#define _MATERIALES_H_

#define MAX_MATERIAL 10
#define WIDTH 50
#define HEIGHT 50
#define ALIVE 1
#define DEATH 0

class material {
	protected:
		int name;
		int state;
	public:
		material(int name, int state) : name(name), state(state) {};

		material() : name(0), state(0) {}

		virtual ~material() {}

		virtual void reaccionar(material* current[WIDTH][HEIGHT], material* update[WIDTH][HEIGHT], int x, int y) {};

		int getEstado() {
			return state;
		}

		int num_neighbors(material* content[WIDTH][HEIGHT], int x, int y);
};


class alive : public material {
	public:
		alive() : material(ALIVE, 0) {};
		~alive() {}
		void reaccionar(material* current[WIDTH][HEIGHT], material* update[WIDTH][HEIGHT], int x, int y);
};

class death : public material {
	public:
		death() : material(DEATH, 0) {};
		~death() {}
		void reaccionar(material* current[WIDTH][HEIGHT], material* update[WIDTH][HEIGHT], int x, int y);
};

#endif /* MATERIALES_H */

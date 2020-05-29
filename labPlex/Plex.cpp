#include "Plex.h"
#include<fstream>
#include<iostream>
#include<sstream>
#include<vector>
#include<stack>
#include<cassert>
#include<set>

Plex::Plex(TLine * tmp) {
	if (tmp == nullptr) start = new TLine();
	else start = new TLine(*tmp);
}

void dfsCopy(TBase* start, TBase* x) {
	if (x->GetType() == _Point) {
		start = new TPoint(*((TPoint*)(x)));
	}
	else if (x->GetType() == _Line) {
		start = new TLine(*((TLine*)(x)));
		if (((TLine*)(x))->GetLeft()) {
			dfsCopy(((TLine*)(start))->GetLeft(), ((TLine*)(x))->GetLeft());
		}
		if (((TLine*)(x))->GetRight()) {
			dfsCopy(((TLine*)(start))->GetRight(), ((TLine*)(x))->GetRight());
		}
	}
}

Plex::Plex(const Plex & tmp) {
	dfsCopy(start, tmp.start);
}

Plex & Plex::operator=(const Plex & tmp) {
	if (this == &tmp) return *this;
	if (start) delete start;
	dfsCopy(start, tmp.start);
	return *this;
}

void Plex::InsertLine(TLine * le, TLine * ri) {
	if (le->GetLeft()->GetName() == ri->GetLeft()->GetName()) {
		ri->SetLeft(le->GetLeft());
		le->SetLeft(ri);
	}
	else {
		ri->SetLeft(le->GetRight());
		le->SetRight(ri);
	}
}

void Plex::addLine(TLine * tm) {
	TLine* tmp = new TLine(*tm);
	std::fstream err;
	err.open("Errors.txt", std::ios::out);
	if (start == nullptr) {
		start = tmp;
		return;
	}
	TLine* le = SearchLineWithPoint(tmp->GetLeft()->GetName());
	TLine* ri = SearchLineWithPoint(tmp->GetRight()->GetName());
	if (le && !ri) {
		InsertLine(le, tmp);
	}
	else if (!le && ri) {
		tmp->Inverse();
		InsertLine(ri, tmp);
	}
	else if (le && ri) {
		err << "HERE\n";
		err << "LINK: ";
		err << le->to_string() << ' ' << tmp->to_string() << '\n';
		err << ri->to_string() << '\n';
		InsertLine(le, tmp);
		if (ri->GetLeft()->GetName() == tmp->GetLeft()->GetName()) {
			ri->GetLeft()->IncRating();
			err << "!" << '\n';
			tmp->SetRight(ri->GetLeft());
			tmp->GetRight()->IncRating();
		}
		else {
			tmp->GetRight()->IncRating();
		}

	}
	else {
		assert(0);
	}
	err.close();
}

TLine* dfsSearchLine(TBase* x, int &find, const std::string & name) {
	if (x->GetType() == _Point) {
		if (x->GetName() == name) {
			find = 1;
			return nullptr;
		}
	}
	else if (x->GetType() == _Line) {
		if (((TLine*)(x))->GetLeft()) {
			TLine* ans = dfsSearchLine(((TLine*)(x))->GetLeft(), find, name);
			if (find == 1) {
				find = 2;
				return ((TLine*)(x));
			}
			if (find == 2) return ans;
		}
		if (((TLine*)(x))->GetRight()) {
			TLine* ans = dfsSearchLine(((TLine*)(x))->GetRight(), find, name);
			if (find == 1) {
				find = 2;
				return ((TLine*)(x));
			}
			if (find == 2) return ans;
		}
	}
	return nullptr;
}

TLine* dfsSearchLine(TBase* x, int &find, int X, int Y) {
	if (x->GetType() == _Point) {
		if (((TPoint*)(x))->GetX() == X && ((TPoint*)(x))->GetY() == Y) {
			find = 1;
			return nullptr;
		}
	}
	else if (x->GetType() == _Line) {
		if (((TLine*)(x))->GetLeft()) {
			TLine* ans = dfsSearchLine(((TLine*)(x))->GetLeft(), find, X, Y);
			if (find == 1) {
				find = 2;
				return ((TLine*)(x));
			}
			if (find == 2) return ans;
		}
		if (((TLine*)(x))->GetRight()) {
			TLine* ans = dfsSearchLine(((TLine*)(x))->GetRight(), find, X, Y);
			if (find == 1) {
				find = 2;
				return ((TLine*)(x));
			}
			if (find == 2) return ans;
		}
	}
	return nullptr;
}

TLine * Plex::SearchLineWithPoint(const std::string & name) {
	int find = 0;
	TLine* ans = dfsSearchLine(start, find, name);
	if (find) return ans;
	return nullptr;
}

TLine * Plex::SearchLineWithPoint(int x, int y) {
	int find = 0;
	TLine* ans = dfsSearchLine(start, find, x, y);
	if (find) return ans;
	return nullptr;
}

TPoint* dfsSearchPoint(TBase* x, bool &find, const std::string & name) {
	if (x->GetType() == _Point) {
		if (x->GetName() == name) {
			find = 1;
			return ((TPoint*)(x));
		}
	}
	else if (x->GetType() == _Line) {
		if (((TLine*)(x))->GetLeft()) {
			TPoint* res = dfsSearchPoint(((TLine*)(x))->GetLeft(), find, name);
			if (find) return res;
		}
		if (((TLine*)(x))->GetRight()) {
			TPoint* res = dfsSearchPoint(((TLine*)(x))->GetRight(), find, name);
			if (find) return res;
		}
	}
	return nullptr;
}

TPoint* dfsSearchPoint(TBase* x, bool &find, int X, int Y) {
	if (x->GetType() == _Point) {
		if (((TPoint*)(x))->GetX() == X && ((TPoint*)(x))->GetY() == Y) {
			find = 1;
			return ((TPoint*)(x));
		}
	}
	else if (x->GetType() == _Line) {
		if (((TLine*)(x))->GetLeft()) {
			TPoint* res = dfsSearchPoint(((TLine*)(x))->GetLeft(), find, X, Y);
			if (find) return res;
		}
		if (((TLine*)(x))->GetRight()) {
			TPoint* res = dfsSearchPoint(((TLine*)(x))->GetRight(), find, X, Y);
			if (find) return res;
		}
	}
	return nullptr;
}

TPoint * Plex::SearchPoint(const std::string & name) {
	bool find = 0;
	TPoint* ans = dfsSearchPoint(start, find, name);
	if (find) return ans;
	return nullptr;
}

TPoint * Plex::SearchPoint(int x, int y) {
	bool find = 0;
	TPoint* ans = dfsSearchPoint(start, find, x, y);
	if (find) return ans;
	return nullptr;
}

void dfsReColor(TBase* x, int c) {
	if (x->GetType() == _Point) {
		x->SetColor(c);
		return;
	}
	x->SetColor(c);
	dfsReColor(((TLine*)x)->GetLeft(), c);
	dfsReColor(((TLine*)x)->GetRight(), c);
}

void Plex::reColor(int c) {
	dfsReColor(start, c);
}

void Plex::Move(int dx, int dy) {
	if (start == nullptr) return;
	if (start->GetType() == _Point) {
		((TPoint*)start)->MovePoint(dx, dy);
		return;
	}
	((TLine*)start)->MovePoint(dx, dy);
}

void Plex::Draw(System::Drawing::Graphics ^ g) {
	if (start == nullptr) return;
	if (start->GetType() == _Point) {
		((TPoint*)start)->Draw(g);
		return;
	}
	((TLine*)start)->Draw(g);
}

bool Plex::Empty() const {
	if (start == nullptr) return true;
	return false;
}

void increase_width(std::vector<std::string> & ans, int x) {
	std::string qwe(x, ' ');
	for (auto i : ans) {
		i = qwe + i;
	}
}

void dfsForSaveGraph(TBase* x, int width, int depth, std::vector<std::string> &ans) {
	if (x == nullptr) return;
	if (x->GetType() == _Point) {
		std::string convert = ((TPoint*)(x))->to_string();
		for (int i = 0; i < convert.size(); i++) {
			ans[depth][width + i] = convert[i];
		}
		return;
	}
	if (((TLine*)(x))->GetLeft() != nullptr) {
		dfsForSaveGraph(((TLine*)(x))->GetLeft(), width - (15 - depth) * 5, depth + 4, ans);
	}
	if (((TLine*)(x))->GetRight() != nullptr) {
		dfsForSaveGraph(((TLine*)(x))->GetRight(), width + (15 - depth) * 5, depth + 4, ans);
	}
	std::string convert = ((TLine*)x)->to_string();
	for (int i = 0; i < convert.size(); i++) {
		ans[depth][width + i] = convert[i];
	}
}

void Plex::saveGraph() {
	std::vector<std::string> ans(10000, std::string(10000, ' '));
	dfsForSaveGraph(start, 500, 0, ans);
	std::fstream out;
	out.open("outputGraph.txt", std::ios::out);
	for (auto i : ans) {
		out << i << '\n';
	}
	out.close();
}

void dfsForSaveFile(TBase* x, std::fstream & out) {
	if (x == nullptr) return;
	if (x->GetType() == _Point) {
		std::string convert = ((TPoint*)(x))->to_string();
		out << convert << '\n';
		return;
	}
	if (((TLine*)(x))->GetLeft() != nullptr) {
		dfsForSaveFile(((TLine*)(x))->GetLeft(), out);
	}
	if (((TLine*)(x))->GetRight() != nullptr) {
		dfsForSaveFile(((TLine*)(x))->GetRight(), out);
	}
	out << ((TLine*)(x))->to_string() << '\n';
}

void Plex::saveFile() {
	std::fstream out;
	out.open("outputFile.txt", std::ios::out);
	dfsForSaveFile(start, out);
	out.close();
}

void Plex::readFile(const std::string & fileName) {
	std::ifstream in;
	in.open("inputFile.txt");
	std::string s;
	std::stack<TBase*> st;

	while (getline(in, s)) {

		std::stringstream buf;
		buf << s;
		std::string type;
		buf >> type;
		try {
			if (type == "LINE:") {
				if (st.size() < 2) {
					throw BadSizeStack();
				}
				std::string nameLeft, nameRight;
				buf >> nameLeft >> nameRight;
				TBase* ri = st.top();
				st.pop();
				TBase* le = st.top();
				st.pop();
				std::stringstream parser;
				parser << le->GetName();
				std::string newName;
				std::string fullName;
				parser >> newName;
				fullName += newName;
				parser.clear();
				std::stringstream parser1;
				parser1 << ri->GetName();
				newName.clear();
				parser1 >> newName;
				fullName += ' ' + newName;
				parser1.clear();
				TLine* qwe = new TLine(le, ri, fullName);
				std::cout << qwe->GetName() << '\n';
				st.push((TBase*)qwe);
			}
			else if (type == "POINT:") {
				std::string name;
				int x, y;
				buf >> name >> x >> y;
				TPoint* p = new TPoint(x, y, name);
				st.push((TBase*)p);
			}
			else throw BadTypeString();
		}
		catch (Plex::BadTypeString) {
			std::cout << "Bad format of type in input string!\n";
			return;
		}
		catch (Plex::BadSizeStack) {
			std::cout << "Bad format of input string: stack empty!\n";
			return;
		}
		catch (Plex::BadNamePoints) {
			std::cout << "Bad format of input string: names of points not match!\n";
			return;
		}
	}

	try {
		if (st.size() != 1) {
			throw BadSizeStack();
		}
		start = (TBase*)st.top();
		st.pop();
	}
	catch (Plex::BadSizeStack) {
		std::cout << "Bad format of input string: stack empty!\n";
		return;
	}
	if (!start) assert(0);
	in.close();
}

TPoint* dfsGetPointsAndLines(TBase* x, std::vector<TPoint*> &p, std::vector<TLine*> &l) {
	if (x->GetType() == _Point) {
		p.push_back(new TPoint(*(TPoint*)x));
		return (TPoint*)x;
	}
	else if (x->GetType() == _Line) {
		TPoint* le = dfsGetPointsAndLines(((TLine*)x)->GetLeft(), p, l);
		TPoint* ri = dfsGetPointsAndLines(((TLine*)x)->GetRight(), p, l);
		l.push_back(new TLine(le, ri));
		return le;
	}
}

std::pair<std::vector<TPoint*>, std::vector<TLine*>> Plex::getPointsAndLines() {
	std::vector<TPoint*> p;
	std::vector<TLine*> l;
	dfsGetPointsAndLines(start, p, l);
	reverse(l.begin(), l.end());
	std::set<std::string> was;
	std::vector<TPoint*> pp;
	for (auto i : p) {
		if (was.find(i->GetName()) == was.end()) {
			pp.push_back(i);
			was.insert(i->GetName());
		}
	}
	std::pair<std::vector<TPoint*>, std::vector<TLine*> > ans = { pp, l };
	return ans;
}
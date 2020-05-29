#pragma once
#include"TBase.h"
#include"TPoint.h"

class TLine : public TBase {
protected:
	TBase *left;
	TBase *right;
public:
	TLine() {
		left = nullptr;
		right = nullptr;
	}
	TLine(TPoint *_left, TPoint *_right) : TBase(_Line, _left->GetName() + ' ' + _right->GetName(), 7) {
		left = _left;
		right = _right;
	}
	TLine(TBase* _left, TBase* _right, std::string name) : TBase(_Line, name, 7) {
		left = _left;
		right = _right;
	}
	TLine(const TLine & tmp);

	TLine &operator= (const TLine & tmp);
	~TLine() {
		delete left;
		delete right;
	}
	void SetLeft(TBase* tmp);
	void SetRight(TBase* tmp);
	TBase* GetLeft();
	TBase* GetRight();
	void Inverse();
	void Draw(System::Drawing::Graphics^ g) override;
	void IncRating() override;
	bool IsFigure(int _x, int _y) override;
	void MovePoint(int dx, int dy);
	std::string to_string() override;
};


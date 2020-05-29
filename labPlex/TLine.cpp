#include "TLine.h"



TLine::TLine(const TLine & tmp) : TBase(_Line, tmp.left->GetName() + ' ' + tmp.right->GetName(), 7) {

	if (tmp.left->GetType() == _Point) {
		left = new TPoint(*((TPoint*)tmp.left));
	}
	else {
		left = new TLine(*((TLine*)tmp.left));
	}
	if (tmp.right->GetType() == _Point) {
		right = new TPoint(*((TPoint*)tmp.right));
	}
	else {
		right = new TLine(*((TLine*)tmp.right));
	}
	Figure = tmp.Figure;
	Name = tmp.Name;
	Visible = tmp.Visible;
	Color = tmp.Color;
	R = tmp.R;
	Width = tmp.Width;
	Rating = tmp.Rating;
}

TLine & TLine::operator=(const TLine & tmp) {
	if (this == &tmp) return *this;
	if (left) delete left;
	if (right) delete right;
	if (tmp.left->GetType() == _Point) {
		left = new TPoint(*((TPoint*)tmp.left));
	}
	else {
		left = new TLine(*((TLine*)tmp.left));
	}
	if (tmp.right->GetType() == _Point) {
		right = new TPoint(*((TPoint*)tmp.right));
	}
	else {
		right = new TLine(*((TLine*)tmp.right));
	}
	Figure = tmp.Figure;
	Name = tmp.Name;
	Visible = tmp.Visible;
	Color = tmp.Color;
	R = tmp.R;
	Width = tmp.Width;
	Rating = tmp.Rating;
	return *this;
}

void TLine::SetLeft(TBase * tmp) {
	left = tmp;
}

void TLine::SetRight(TBase * tmp) {
	right = tmp;
}

TBase * TLine::GetLeft() {
	return left;
}

TBase * TLine::GetRight() {
	return right;
}

void TLine::Inverse() {
	TBase* tmp = left;
	left = right;
	right = tmp;
	std::string newName;
	int index = Name.find(' ');
	newName += Name.substr(index + 1, Name.size());
	newName += ' ';
	newName += Name.substr(0, index);
	Name = newName;
}

TBase* dfsDraw(TBase* x, System::Drawing::Graphics ^ g, System::Drawing::Pen^ pen, System::Drawing::SolidBrush^ brush) {
	if (x->GetType() == _Point) {
		g->FillEllipse(brush, ((TPoint*)x)->GetX(), ((TPoint*)x)->GetY(), ((TPoint*)x)->GetWidth(), ((TPoint*)x)->GetWidth());
		return x;
	}

	TBase* le = dfsDraw(((TLine*)x)->GetLeft(), g, pen, brush);
	TBase* ri = dfsDraw(((TLine*)x)->GetRight(), g, pen, brush);
	g->DrawLine(pen, ((TPoint*)le)->GetX() + ((TPoint*)le)->GetWidth() / 2, ((TPoint*)le)->GetY() + ((TPoint*)le)->GetWidth() / 2,
		((TPoint*)ri)->GetX() + ((TPoint*)ri)->GetWidth() / 2, ((TPoint*)ri)->GetY() + ((TPoint*)ri)->GetWidth() / 2);
	return le;

}

void TLine::Draw(System::Drawing::Graphics ^ g) {
	if (!Visible) return;
	int red, green, blue;
	int tmp = Color;

	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(
		System::Drawing::Color::FromArgb(tmp));
	System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(
		System::Drawing::Color::FromArgb(tmp));
	pen->Width = R;
	TBase* le = dfsDraw(left, g, pen, brush);
	TBase* ri = dfsDraw(right, g, pen, brush);
	g->DrawLine(pen, ((TPoint*)le)->GetX() + ((TPoint*)le)->GetWidth() / 2, ((TPoint*)le)->GetY() + ((TPoint*)le)->GetWidth() / 2,
		((TPoint*)ri)->GetX() + ((TPoint*)ri)->GetWidth() / 2, ((TPoint*)ri)->GetY() + ((TPoint*)ri)->GetWidth() / 2);
}

void TLine::IncRating() {
	Rating++;
	if (Rating == 4) Rating = 1;
}

bool TLine::IsFigure(int _x, int _y) {
	if (left->IsFigure(_x, _y) || right->IsFigure(_x, _y)) return true;
}

void TLine::MovePoint(int dx, int dy) {
	if (left->GetType() == _Point) {
		((TPoint*)left)->MovePoint(dx, dy);
	}
	else {
		((TLine*)left)->MovePoint(dx, dy);
	}
	if (right->GetType() == _Point) {
		((TPoint*)right)->MovePoint(dx, dy);
	}
	else {
		((TLine*)right)->MovePoint(dx, dy);
	}
}

std::string TLine::to_string() {
	std::string ans;
	ans += "LINE: ";
	ans += GetName();
	return ans;
}


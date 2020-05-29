#include "TBase.h"

TBase::TBase(const TBase & tmp) {
	Figure = tmp.Figure;
	Name = tmp.Name;
	Visible = tmp.Visible;
	Color = tmp.Color;
	R = tmp.R;
	Width = tmp.Width;
	Rating = tmp.Rating;
}

TypeFigure TBase::GetType() const {
	return Figure;
}

bool TBase::GetVisability() const {
	return Visible;
}

int TBase::GetWidth() const {
	return Width;
}

int TBase::GetRating() const {
	return Rating;
}

std::string TBase::GetName() const {
	return Name;
}

int TBase::GetColor() const {
	return Color;
}

void TBase::SetColor(int _c) {
	Color = _c;
}

void TBase::SetWidth(int _width) {
	Width = _width;
}

void TBase::SetVisability(bool _vis) {
	Visible = _vis;
}
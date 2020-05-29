#pragma once
#include"TPoint.h"
#include"TLine.h"
#include<vector>
#include<set>
#include<queue>
#include<iostream>
#include <msclr\marshal_cppstd.h>
#include"Plex.h"

namespace labPlex {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	std::vector<TPoint*> Dots;
	std::vector<TLine*> Lines;
	Plex *flex = nullptr;

	std::set<TPoint> setik;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Exit_button;
	private: System::Windows::Forms::PictureBox^  picture;
	private: System::Windows::Forms::DataGridView^  GridDots;
	private: System::Windows::Forms::DataGridView^  GridLines;


	private: System::Windows::Forms::Label^  Move_Point_label;
	private: System::Windows::Forms::TextBox^  MovePoint_Name_textBox;
	private: System::Windows::Forms::TextBox^  MovePoint_dx_textBox;
	private: System::Windows::Forms::TextBox^  MovePoint_dy_textBox;


	private: System::Windows::Forms::Label^  MovePoint_Name_label;
	private: System::Windows::Forms::Label^  MovePoint_dx_label;
	private: System::Windows::Forms::Label^  MovePoint_dy_label;
	private: System::Windows::Forms::Button^  Move_button;
	private: System::Windows::Forms::Label^  CreateLine_label;
	private: System::Windows::Forms::TextBox^  CreateLine_Name1_textBox;
	private: System::Windows::Forms::TextBox^  CreateLine_Name2_textBox;
	private: System::Windows::Forms::Label^  CreateLine_Name1_label;
	private: System::Windows::Forms::Label^  CreateLine_Name2_label;
	private: System::Windows::Forms::Button^  Create_button;
	private: System::Windows::Forms::Button^  Clear_button;
	private: System::Windows::Forms::Button^  Save_file_button;
	private: System::Windows::Forms::Button^  Load_Plex_button;


	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::Button^  ChangeColor_button;



	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Exit_button = (gcnew System::Windows::Forms::Button());
			this->picture = (gcnew System::Windows::Forms::PictureBox());
			this->GridDots = (gcnew System::Windows::Forms::DataGridView());
			this->GridLines = (gcnew System::Windows::Forms::DataGridView());
			this->Move_Point_label = (gcnew System::Windows::Forms::Label());
			this->MovePoint_Name_textBox = (gcnew System::Windows::Forms::TextBox());
			this->MovePoint_dx_textBox = (gcnew System::Windows::Forms::TextBox());
			this->MovePoint_dy_textBox = (gcnew System::Windows::Forms::TextBox());
			this->MovePoint_Name_label = (gcnew System::Windows::Forms::Label());
			this->MovePoint_dx_label = (gcnew System::Windows::Forms::Label());
			this->MovePoint_dy_label = (gcnew System::Windows::Forms::Label());
			this->Move_button = (gcnew System::Windows::Forms::Button());
			this->CreateLine_label = (gcnew System::Windows::Forms::Label());
			this->CreateLine_Name1_textBox = (gcnew System::Windows::Forms::TextBox());
			this->CreateLine_Name2_textBox = (gcnew System::Windows::Forms::TextBox());
			this->CreateLine_Name1_label = (gcnew System::Windows::Forms::Label());
			this->CreateLine_Name2_label = (gcnew System::Windows::Forms::Label());
			this->Create_button = (gcnew System::Windows::Forms::Button());
			this->Clear_button = (gcnew System::Windows::Forms::Button());
			this->Save_file_button = (gcnew System::Windows::Forms::Button());
			this->Load_Plex_button = (gcnew System::Windows::Forms::Button());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->ChangeColor_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridDots))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridLines))->BeginInit();
			this->SuspendLayout();
			// 
			// Exit_button
			// 
			this->Exit_button->Location = System::Drawing::Point(12, 550);
			this->Exit_button->Name = L"Exit_button";
			this->Exit_button->Size = System::Drawing::Size(141, 43);
			this->Exit_button->TabIndex = 0;
			this->Exit_button->Text = L"Exit";
			this->Exit_button->UseVisualStyleBackColor = true;
			this->Exit_button->Click += gcnew System::EventHandler(this, &MyForm::Exit_button_Click);
			// 
			// picture
			// 
			this->picture->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->picture->Location = System::Drawing::Point(405, 12);
			this->picture->Name = L"picture";
			this->picture->Size = System::Drawing::Size(681, 493);
			this->picture->TabIndex = 1;
			this->picture->TabStop = false;
			this->picture->Click += gcnew System::EventHandler(this, &MyForm::picture_Click);
			this->picture->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::picture_MouseDown);
			// 
			// GridDots
			// 
			this->GridDots->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->GridDots->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->GridDots->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->GridDots->ColumnHeadersVisible = false;
			this->GridDots->Location = System::Drawing::Point(159, 12);
			this->GridDots->Name = L"GridDots";
			this->GridDots->RowHeadersVisible = false;
			this->GridDots->Size = System::Drawing::Size(240, 228);
			this->GridDots->TabIndex = 2;
			this->GridDots->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::GridDots_CellContentClick);
			// 
			// GridLines
			// 
			this->GridLines->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->GridLines->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->GridLines->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->GridLines->ColumnHeadersVisible = false;
			this->GridLines->Location = System::Drawing::Point(159, 246);
			this->GridLines->Name = L"GridLines";
			this->GridLines->RowHeadersVisible = false;
			this->GridLines->Size = System::Drawing::Size(240, 240);
			this->GridLines->TabIndex = 3;
			this->GridLines->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::GridLines_CellContentClick);
			// 
			// Move_Point_label
			// 
			this->Move_Point_label->AutoSize = true;
			this->Move_Point_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Move_Point_label->Location = System::Drawing::Point(9, 12);
			this->Move_Point_label->Name = L"Move_Point_label";
			this->Move_Point_label->Size = System::Drawing::Size(71, 13);
			this->Move_Point_label->TabIndex = 4;
			this->Move_Point_label->Text = L"Move Point";
			this->Move_Point_label->Click += gcnew System::EventHandler(this, &MyForm::Move_Point_label_Click);
			// 
			// MovePoint_Name_textBox
			// 
			this->MovePoint_Name_textBox->Location = System::Drawing::Point(53, 37);
			this->MovePoint_Name_textBox->Name = L"MovePoint_Name_textBox";
			this->MovePoint_Name_textBox->Size = System::Drawing::Size(100, 20);
			this->MovePoint_Name_textBox->TabIndex = 5;
			this->MovePoint_Name_textBox->TextChanged += gcnew System::EventHandler(this, &MyForm::MovePoint_Name_textBox_TextChanged);
			// 
			// MovePoint_dx_textBox
			// 
			this->MovePoint_dx_textBox->Location = System::Drawing::Point(53, 63);
			this->MovePoint_dx_textBox->Name = L"MovePoint_dx_textBox";
			this->MovePoint_dx_textBox->Size = System::Drawing::Size(38, 20);
			this->MovePoint_dx_textBox->TabIndex = 6;
			this->MovePoint_dx_textBox->TextChanged += gcnew System::EventHandler(this, &MyForm::MovePoint_dx_textBox_TextChanged);
			// 
			// MovePoint_dy_textBox
			// 
			this->MovePoint_dy_textBox->Location = System::Drawing::Point(53, 89);
			this->MovePoint_dy_textBox->Name = L"MovePoint_dy_textBox";
			this->MovePoint_dy_textBox->Size = System::Drawing::Size(38, 20);
			this->MovePoint_dy_textBox->TabIndex = 7;
			this->MovePoint_dy_textBox->TextChanged += gcnew System::EventHandler(this, &MyForm::MovePoint_dy_textBox_TextChanged);
			// 
			// MovePoint_Name_label
			// 
			this->MovePoint_Name_label->AutoSize = true;
			this->MovePoint_Name_label->Location = System::Drawing::Point(6, 40);
			this->MovePoint_Name_label->Name = L"MovePoint_Name_label";
			this->MovePoint_Name_label->Size = System::Drawing::Size(41, 13);
			this->MovePoint_Name_label->TabIndex = 8;
			this->MovePoint_Name_label->Text = L"Name :";
			this->MovePoint_Name_label->Click += gcnew System::EventHandler(this, &MyForm::MovePoint_Name_label_Click);
			// 
			// MovePoint_dx_label
			// 
			this->MovePoint_dx_label->AutoSize = true;
			this->MovePoint_dx_label->Location = System::Drawing::Point(15, 66);
			this->MovePoint_dx_label->Name = L"MovePoint_dx_label";
			this->MovePoint_dx_label->Size = System::Drawing::Size(27, 13);
			this->MovePoint_dx_label->TabIndex = 9;
			this->MovePoint_dx_label->Text = L"dx : ";
			this->MovePoint_dx_label->Click += gcnew System::EventHandler(this, &MyForm::MovePoint_dx_label_Click);
			// 
			// MovePoint_dy_label
			// 
			this->MovePoint_dy_label->AutoSize = true;
			this->MovePoint_dy_label->Location = System::Drawing::Point(15, 92);
			this->MovePoint_dy_label->Name = L"MovePoint_dy_label";
			this->MovePoint_dy_label->Size = System::Drawing::Size(24, 13);
			this->MovePoint_dy_label->TabIndex = 10;
			this->MovePoint_dy_label->Text = L"dy :";
			this->MovePoint_dy_label->Click += gcnew System::EventHandler(this, &MyForm::MovePoint_dy_label_Click);
			// 
			// Move_button
			// 
			this->Move_button->Location = System::Drawing::Point(9, 115);
			this->Move_button->Name = L"Move_button";
			this->Move_button->Size = System::Drawing::Size(144, 53);
			this->Move_button->TabIndex = 11;
			this->Move_button->Text = L"Move";
			this->Move_button->UseVisualStyleBackColor = true;
			this->Move_button->Click += gcnew System::EventHandler(this, &MyForm::Move_button_Click);
			// 
			// CreateLine_label
			// 
			this->CreateLine_label->AutoSize = true;
			this->CreateLine_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CreateLine_label->Location = System::Drawing::Point(9, 246);
			this->CreateLine_label->Name = L"CreateLine_label";
			this->CreateLine_label->Size = System::Drawing::Size(72, 13);
			this->CreateLine_label->TabIndex = 12;
			this->CreateLine_label->Text = L"Create Line";
			this->CreateLine_label->Click += gcnew System::EventHandler(this, &MyForm::CreateLine_label_Click);
			// 
			// CreateLine_Name1_textBox
			// 
			this->CreateLine_Name1_textBox->Location = System::Drawing::Point(65, 281);
			this->CreateLine_Name1_textBox->Name = L"CreateLine_Name1_textBox";
			this->CreateLine_Name1_textBox->Size = System::Drawing::Size(88, 20);
			this->CreateLine_Name1_textBox->TabIndex = 13;
			this->CreateLine_Name1_textBox->TextChanged += gcnew System::EventHandler(this, &MyForm::CreateLine_Name1_textBox_TextChanged);
			// 
			// CreateLine_Name2_textBox
			// 
			this->CreateLine_Name2_textBox->Location = System::Drawing::Point(65, 307);
			this->CreateLine_Name2_textBox->Name = L"CreateLine_Name2_textBox";
			this->CreateLine_Name2_textBox->Size = System::Drawing::Size(88, 20);
			this->CreateLine_Name2_textBox->TabIndex = 14;
			this->CreateLine_Name2_textBox->TextChanged += gcnew System::EventHandler(this, &MyForm::CreateLine_Name2_textBox_TextChanged);
			// 
			// CreateLine_Name1_label
			// 
			this->CreateLine_Name1_label->AutoSize = true;
			this->CreateLine_Name1_label->Location = System::Drawing::Point(6, 284);
			this->CreateLine_Name1_label->Name = L"CreateLine_Name1_label";
			this->CreateLine_Name1_label->Size = System::Drawing::Size(50, 13);
			this->CreateLine_Name1_label->TabIndex = 15;
			this->CreateLine_Name1_label->Text = L"Name 1 :";
			this->CreateLine_Name1_label->Click += gcnew System::EventHandler(this, &MyForm::CreateLine_Name1_label_Click);
			// 
			// CreateLine_Name2_label
			// 
			this->CreateLine_Name2_label->AutoSize = true;
			this->CreateLine_Name2_label->Location = System::Drawing::Point(6, 310);
			this->CreateLine_Name2_label->Name = L"CreateLine_Name2_label";
			this->CreateLine_Name2_label->Size = System::Drawing::Size(50, 13);
			this->CreateLine_Name2_label->TabIndex = 16;
			this->CreateLine_Name2_label->Text = L"Name 2 :";
			this->CreateLine_Name2_label->Click += gcnew System::EventHandler(this, &MyForm::CreateLine_Name2_label_Click);
			// 
			// Create_button
			// 
			this->Create_button->Location = System::Drawing::Point(9, 333);
			this->Create_button->Name = L"Create_button";
			this->Create_button->Size = System::Drawing::Size(144, 54);
			this->Create_button->TabIndex = 17;
			this->Create_button->Text = L"Create";
			this->Create_button->UseVisualStyleBackColor = true;
			this->Create_button->Click += gcnew System::EventHandler(this, &MyForm::Create_button_Click);
			// 
			// Clear_button
			// 
			this->Clear_button->Location = System::Drawing::Point(12, 492);
			this->Clear_button->Name = L"Clear_button";
			this->Clear_button->Size = System::Drawing::Size(141, 52);
			this->Clear_button->TabIndex = 18;
			this->Clear_button->Text = L"Clear";
			this->Clear_button->UseVisualStyleBackColor = true;
			this->Clear_button->Click += gcnew System::EventHandler(this, &MyForm::Clear_button_Click);
			// 
			// Save_file_button
			// 
			this->Save_file_button->Location = System::Drawing::Point(206, 550);
			this->Save_file_button->Name = L"Save_file_button";
			this->Save_file_button->Size = System::Drawing::Size(167, 43);
			this->Save_file_button->TabIndex = 19;
			this->Save_file_button->Text = L"Save File";
			this->Save_file_button->UseVisualStyleBackColor = true;
			this->Save_file_button->Click += gcnew System::EventHandler(this, &MyForm::Save_file_button_Click);
			// 
			// Load_Plex_button
			// 
			this->Load_Plex_button->Location = System::Drawing::Point(379, 550);
			this->Load_Plex_button->Name = L"Load_Plex_button";
			this->Load_Plex_button->Size = System::Drawing::Size(168, 43);
			this->Load_Plex_button->TabIndex = 20;
			this->Load_Plex_button->Text = L"Load Plex";
			this->Load_Plex_button->UseVisualStyleBackColor = true;
			this->Load_Plex_button->Click += gcnew System::EventHandler(this, &MyForm::Load_Plex_button_Click);
			// 
			// ChangeColor_button
			// 
			this->ChangeColor_button->Location = System::Drawing::Point(553, 550);
			this->ChangeColor_button->Name = L"ChangeColor_button";
			this->ChangeColor_button->Size = System::Drawing::Size(168, 43);
			this->ChangeColor_button->TabIndex = 23;
			this->ChangeColor_button->Text = L"Change Color";
			this->ChangeColor_button->UseVisualStyleBackColor = true;
			this->ChangeColor_button->Click += gcnew System::EventHandler(this, &MyForm::ChangeColor_button_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1098, 605);
			this->Controls->Add(this->ChangeColor_button);
			this->Controls->Add(this->Load_Plex_button);
			this->Controls->Add(this->Save_file_button);
			this->Controls->Add(this->Clear_button);
			this->Controls->Add(this->Create_button);
			this->Controls->Add(this->CreateLine_Name2_label);
			this->Controls->Add(this->CreateLine_Name1_label);
			this->Controls->Add(this->CreateLine_Name2_textBox);
			this->Controls->Add(this->CreateLine_Name1_textBox);
			this->Controls->Add(this->CreateLine_label);
			this->Controls->Add(this->Move_button);
			this->Controls->Add(this->MovePoint_dy_label);
			this->Controls->Add(this->MovePoint_dx_label);
			this->Controls->Add(this->MovePoint_Name_label);
			this->Controls->Add(this->MovePoint_dy_textBox);
			this->Controls->Add(this->MovePoint_dx_textBox);
			this->Controls->Add(this->MovePoint_Name_textBox);
			this->Controls->Add(this->Move_Point_label);
			this->Controls->Add(this->GridLines);
			this->Controls->Add(this->GridDots);
			this->Controls->Add(this->picture);
			this->Controls->Add(this->Exit_button);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picture))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridDots))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridLines))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:
			Graphics^ g;
			Bitmap^ Im;
			SolidBrush^ Brush;
			int DotName = -1;
			int COLOR = -16777216;
			

			void PrintDotsDataGrid() {
				GridDots->RowCount = Dots.size();
				GridDots->ColumnCount = 3;
				GridDots->Columns[0]->HeaderCell->Value = "Name";
				GridDots->Columns[1]->HeaderCell->Value = "X";
				GridDots->Columns[2]->HeaderCell->Value = "Y";
				for (int i = 0; i < Dots.size(); i++) {
					GridDots->Rows[i]->Cells[0]->Value = msclr::interop::marshal_as<String^>(Dots[i]->GetName());
					GridDots->Rows[i]->Cells[1]->Value = System::Convert::ToString(Dots[i]->GetX());
					GridDots->Rows[i]->Cells[2]->Value = System::Convert::ToString(Dots[i]->GetY());
				}
			}

			std::string TranslateTo26(int x) {
				std::string ans;
				while (x) {
					ans += char(x % 26 + 'A');
					x /= 26;
				}
				std::reverse(ans.begin(), ans.end());
				if (ans.size() == 0) {
					ans += 'A';
				}
				return ans;
			}

			std::string GenerateNewName() {
				return TranslateTo26(++DotName);
			}
			int FindNameInDots(std::string s) {
				for (int i = 0; i < Dots.size(); i++) {
					if (Dots[i]->GetName() == s) return i;
				}
				return -1;
			}

			void ClearPictureBox() {
				Im = gcnew Bitmap(picture->Width, picture->Height);
				g->Clear(Color::White);
				picture->Image = Im;
				picture->Image = Im;
				picture->Refresh();
				picture->Invalidate();
			}
	private: System::Void Exit_button_Click(System::Object^  sender, System::EventArgs^  e) {
		Close();
	}
	private: System::Void picture_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void Move_Point_label_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void MovePoint_Name_textBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MovePoint_dx_textBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MovePoint_dy_textBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MovePoint_Name_label_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MovePoint_dx_label_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MovePoint_dy_label_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Move_button_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string NamePointToMove = msclr::interop::marshal_as<std::string>(MovePoint_Name_textBox->Text);
	int dx = System::Convert::ToInt32(MovePoint_dx_textBox->Text);
	int dy = System::Convert::ToInt32(MovePoint_dy_textBox->Text);
	int index = FindNameInDots(NamePointToMove);
	if (index == -1) {
		MessageBox::Show("Такого имени точки не существует!");
		return;
	}

	if (flex) {
		TPoint* find = flex->SearchPoint(NamePointToMove);

		if (find) {
			find->MovePoint(dx, dy);
		}
		flex->saveFile();
		flex->saveGraph();
	}
	Dots[index]->MovePoint(dx, dy);
	if (Dots.size()) PrintDotsDataGrid();
	if (Lines.size()) PrintLinesDataGrid();

	ClearPictureBox();

	DrawLines();
	DrawDots();

}
		 void DrawDots() {
			 for (int i = 0; i < Dots.size(); i++) {
				 delete g;
				 g = Graphics::FromImage(Im);
				 picture->Image = Im;
				 Dots[i]->SetColor(COLOR);
				 Dots[i]->Draw(g);
				 picture->Refresh();
				 picture->Invalidate();
			 }
		 }

		 void DrawLines() {
			 for (int i = 0; i < Lines.size(); i++) {
				 delete g;
				 g = Graphics::FromImage(Im);
				 picture->Image = Im;
				 Lines[i]->SetColor(COLOR);
				 Lines[i]->Draw(g);
				 picture->Refresh();
				 picture->Invalidate();
			 }
		 }

		 void PrintLinesDataGrid() {
			 GridLines->RowCount = Lines.size();
			 GridLines->ColumnCount = 5;
			 GridLines->Columns[0]->HeaderCell->Value = "Name";
			 GridLines->Columns[1]->HeaderCell->Value = "X1";
			 GridLines->Columns[2]->HeaderCell->Value = "Y1";
			 GridLines->Columns[3]->HeaderCell->Value = "X2";
			 GridLines->Columns[4]->HeaderCell->Value = "Y2";
			 for (int i = 0; i < Lines.size(); i++) {
				 GridLines->Rows[i]->Cells[0]->Value = msclr::interop::marshal_as<String^>(Lines[i]->GetName());
				 GridLines->Rows[i]->Cells[1]->Value = System::Convert::ToString(((TPoint*)(Lines[i]->GetLeft()))->GetX());
				 GridLines->Rows[i]->Cells[2]->Value = System::Convert::ToString(((TPoint*)(Lines[i]->GetLeft()))->GetY());
				 GridLines->Rows[i]->Cells[3]->Value = System::Convert::ToString(((TPoint*)(Lines[i]->GetRight()))->GetX());
				 GridLines->Rows[i]->Cells[4]->Value = System::Convert::ToString(((TPoint*)(Lines[i]->GetRight()))->GetY());
			 }
		 }

private: System::Void CreateLine_label_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void CreateLine_Name1_textBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void CreateLine_Name2_textBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void CreateLine_Name1_label_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void CreateLine_Name2_label_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Create_button_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string Name1 = msclr::interop::marshal_as<std::string>(CreateLine_Name1_textBox->Text);
	std::string Name2 = msclr::interop::marshal_as<std::string>(CreateLine_Name2_textBox->Text);
	int ind1 = FindNameInDots(Name1);
	int ind2 = FindNameInDots(Name2);
	if (ind1 == -1 || ind2 == -1) {
		MessageBox::Show("Такого имени точки не существует!");
		return;
	}
	std::string NameLine = Name1 + ' ' + Name2;
	Lines.push_back(new TLine(Dots[ind1], Dots[ind2]));
	DrawLines();
	PrintLinesDataGrid();
}
private: System::Void Clear_button_Click(System::Object^  sender, System::EventArgs^  e) {
	ClearPictureBox();
	Dots.clear();
	Lines.clear();
	delete flex;
	flex = new Plex();
	delete g;
	g = Graphics::FromImage(Im);
	picture->Image = Im;
	picture->Refresh();
	picture->Invalidate();
}
private: System::Void GridDots_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void GridLines_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void picture_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	Im = gcnew Bitmap(picture->Image);
	int X = e->X;
	int Y = e->Y;
	std::string name = GenerateNewName();

	Dots.push_back(new TPoint(X, Y, name));
	Dots.back()->SetColor(COLOR);
	//MessageBox::Show(System::Convert::ToString(mas.size()));
	PrintDotsDataGrid();
	DrawDots();
}
	/*private: System::Void picture_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		int X = e->X;
		int Y = e->Y;
		for (int i = 0; i < Dots.size(); i++) {
			if (Dots[i]->IsFigure(X, Y)) {
				CurrentDot_textBox->Text = msclr::interop::marshal_as<String^>(Dots[i]->GetName());
				return;
			}
		}
	}*/
private: System::Void Save_file_button_Click(System::Object^  sender, System::EventArgs^  e) {
	if (!Lines.size()) return;
	setik.clear();

	/*String^ kek = msclr::interop::marshal_as<String^>(Lines[0]->GetName());
	MessageBox::Show(kek);*/

	flex = new Plex(Lines[0]);
	setik.insert(*((TPoint*)Lines[0]->GetLeft()));
	setik.insert(*((TPoint*)Lines[0]->GetRight()));
	std::queue<TLine*> q;
	for (int i = 1; i < Lines.size(); i++) {
		if (setik.find(*(TPoint*)(Lines[i]->GetLeft())) != setik.end() ||
			setik.find(*(TPoint*)(Lines[i]->GetRight())) != setik.end()) {
			flex->addLine(Lines[i]);
			setik.insert(*(TPoint*)(Lines[i]->GetLeft()));
			setik.insert(*(TPoint*)(Lines[i]->GetRight()));
		}
		else {
			q.push(Lines[i]);
		}
	}
	int cnt = 0;
	while (!q.empty()) {
		if (cnt == 1e5) break;
		cnt++;
		TLine* cur = q.front();
		q.pop();
		if (setik.find(*(TPoint*)(cur->GetLeft())) != setik.end() ||
			setik.find(*(TPoint*)(cur->GetRight())) != setik.end()) {
			flex->addLine(cur);
			setik.insert(*(TPoint*)(cur->GetLeft()));
			setik.insert(*(TPoint*)(cur->GetRight()));
		}
		else {
			q.push(cur);
		}
	}
	flex->saveFile();
	flex->saveGraph();
	flex->reColor(COLOR);
	PrintLinesDataGrid();
}
private: System::Void Load_Plex_button_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string name = "outputFile.txt";
	if (!flex) flex = new Plex();
	flex->readFile(name);
	auto ans = flex->getPointsAndLines();
	Dots.clear();
	Lines.clear();
	Dots = ans.first;
	Lines = ans.second;
	if (Dots.size()) PrintDotsDataGrid();
	if (Lines.size()) PrintLinesDataGrid();
	DotName = Lines.size() - 1;
	flex->reColor(COLOR);

	ClearPictureBox();
	if (flex == nullptr || flex->Empty()) return;
	delete g;
	g = Graphics::FromImage(Im);
	picture->Image = Im;
	flex->reColor(COLOR);
	flex->Draw(g);
	picture->Refresh();
	picture->Invalidate();
}
/*private: System::Void Change_Color_button_Click(System::Object^  sender, System::EventArgs^  e) {
	if (colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		COLOR = colorDialog1->Color.ToArgb();
		//MessageBox::Show(System::Convert::ToString(COLOR));
		for (auto i : Dots) {
			i->SetColor(COLOR);
		}
		for (auto i : Lines) {
			i->SetColor(COLOR);
		}
		DrawPlexButton_Click(sender, e);
		DrawPictButton_Click(sender, e);
	}
}*/
private: System::Void CurrentDot_textBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void CurrentDot_label_Click(System::Object^  sender, System::EventArgs^  e) {
}
	private: System::Void ChangeColor_button_Click(System::Object^  sender, System::EventArgs^  e) {
		if (colorDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			COLOR = colorDialog1->Color.ToArgb();
			//MessageBox::Show(System::Convert::ToString(COLOR));
			for (auto i : Dots) {
				i->SetColor(COLOR);
			}
			for (auto i : Lines) {
				i->SetColor(COLOR);
			}
			/*DrawPlexButton_Click(sender, e);
			DrawPictButton_Click(sender, e);*/
		}
	}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	Im = gcnew Bitmap(picture->Width, picture->Height);
	g = Graphics::FromImage(Im);
	picture->Image = Im;
}
};
}

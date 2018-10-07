#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include "text.h"
#include <cstddef>
#include <msclr\marshal_cppstd.h>
#include <fstream>

namespace LEDgui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel3;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::ComboBox^  comboBox3;




	private: System::Windows::Forms::TextBox^  textBox17;
	private: System::Windows::Forms::TextBox^  textBox18;










	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel3 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->flowLayoutPanel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Small (4 Lines Fit)", L"Medium (2 Lines Fit)",
					L"Large (1 Line Fits)"
			});
			this->comboBox1->Location = System::Drawing::Point(195, 71);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(145, 24);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			this->comboBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::comboBox1_MouseClick);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::MintCream;
			this->button2->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(3, 39);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(185, 25);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Choose Text Color:";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(194, 39);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(81, 22);
			this->textBox1->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::MintCream;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(3, 70);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(185, 25);
			this->textBox2->TabIndex = 6;
			this->textBox2->Text = L"Choose Text Size:";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->textBox3->BackColor = System::Drawing::Color::Black;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Cursor = System::Windows::Forms::Cursors::Default;
			this->textBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->ForeColor = System::Drawing::Color::Lime;
			this->textBox3->HideSelection = false;
			this->textBox3->Location = System::Drawing::Point(0, 0);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(1049, 46);
			this->textBox3->TabIndex = 7;
			this->textBox3->Text = L"LED MATRIX Control System";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
			this->textBox3->GotFocus += gcnew System::EventHandler(this, &MyForm::textBox3_GotFocus);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::Transparent;
			this->flowLayoutPanel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->flowLayoutPanel1->Controls->Add(this->textBox7);
			this->flowLayoutPanel1->Controls->Add(this->button2);
			this->flowLayoutPanel1->Controls->Add(this->textBox1);
			this->flowLayoutPanel1->Controls->Add(this->textBox2);
			this->flowLayoutPanel1->Controls->Add(this->comboBox1);
			this->flowLayoutPanel1->Controls->Add(this->textBox6);
			this->flowLayoutPanel1->Controls->Add(this->comboBox2);
			this->flowLayoutPanel1->Controls->Add(this->textBox4);
			this->flowLayoutPanel1->Controls->Add(this->textBox5);
			this->flowLayoutPanel1->Controls->Add(this->button1);
			this->flowLayoutPanel1->Location = System::Drawing::Point(474, 52);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(354, 230);
			this->flowLayoutPanel1->TabIndex = 8;
			// 
			// textBox7
			// 
			this->textBox7->BackColor = System::Drawing::Color::Black;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox7->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->textBox7->Location = System::Drawing::Point(3, 3);
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(339, 30);
			this->textBox7->TabIndex = 9;
			this->textBox7->Text = L"Text Controls";
			this->textBox7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox7_TextChanged);
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::Color::MintCream;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox6->Location = System::Drawing::Point(3, 102);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(185, 25);
			this->textBox6->TabIndex = 9;
			this->textBox6->Text = L"Choose Text Animation:";
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox6_TextChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"None", L"Flash", L"Scroll", L"Wave" });
			this->comboBox2->Location = System::Drawing::Point(195, 103);
			this->comboBox2->Margin = System::Windows::Forms::Padding(4);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(145, 24);
			this->comboBox2->TabIndex = 10;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::MintCream;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(3, 134);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(338, 25);
			this->textBox4->TabIndex = 9;
			this->textBox4->Text = L"Insert Text:";
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::SystemColors::Info;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(3, 165);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(338, 25);
			this->textBox5->TabIndex = 9;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Chartreuse;
			this->button1->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(3, 196);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(84, 27);
			this->button1->TabIndex = 9;
			this->button1->Text = L"ENTER";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->BackColor = System::Drawing::Color::Transparent;
			this->flowLayoutPanel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->flowLayoutPanel2->Controls->Add(this->textBox8);
			this->flowLayoutPanel2->Controls->Add(this->textBox9);
			this->flowLayoutPanel2->Controls->Add(this->textBox10);
			this->flowLayoutPanel2->Controls->Add(this->textBox12);
			this->flowLayoutPanel2->Controls->Add(this->textBox13);
			this->flowLayoutPanel2->Controls->Add(this->button4);
			this->flowLayoutPanel2->Location = System::Drawing::Point(12, 201);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(352, 192);
			this->flowLayoutPanel2->TabIndex = 9;
			// 
			// textBox8
			// 
			this->textBox8->BackColor = System::Drawing::Color::Black;
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox8->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->textBox8->Location = System::Drawing::Point(3, 3);
			this->textBox8->Name = L"textBox8";
			this->textBox8->ReadOnly = true;
			this->textBox8->Size = System::Drawing::Size(339, 30);
			this->textBox8->TabIndex = 9;
			this->textBox8->Text = L"WiFi Settings";
			this->textBox8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox9
			// 
			this->textBox9->BackColor = System::Drawing::Color::MintCream;
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox9->Location = System::Drawing::Point(3, 39);
			this->textBox9->Name = L"textBox9";
			this->textBox9->ReadOnly = true;
			this->textBox9->Size = System::Drawing::Size(338, 25);
			this->textBox9->TabIndex = 10;
			this->textBox9->Text = L"Insert Network ID:";
			this->textBox9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox10
			// 
			this->textBox10->BackColor = System::Drawing::SystemColors::Info;
			this->textBox10->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox10->Location = System::Drawing::Point(3, 70);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(338, 25);
			this->textBox10->TabIndex = 11;
			// 
			// textBox12
			// 
			this->textBox12->BackColor = System::Drawing::Color::MintCream;
			this->textBox12->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox12->Location = System::Drawing::Point(3, 101);
			this->textBox12->Name = L"textBox12";
			this->textBox12->ReadOnly = true;
			this->textBox12->Size = System::Drawing::Size(338, 25);
			this->textBox12->TabIndex = 9;
			this->textBox12->Text = L"Insert Password:";
			this->textBox12->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox13
			// 
			this->textBox13->BackColor = System::Drawing::SystemColors::Info;
			this->textBox13->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox13->Location = System::Drawing::Point(3, 132);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(338, 25);
			this->textBox13->TabIndex = 9;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Chartreuse;
			this->button4->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(3, 163);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(84, 27);
			this->button4->TabIndex = 9;
			this->button4->Text = L"ENTER";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// flowLayoutPanel3
			// 
			this->flowLayoutPanel3->BackColor = System::Drawing::Color::Transparent;
			this->flowLayoutPanel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->flowLayoutPanel3->Controls->Add(this->textBox11);
			this->flowLayoutPanel3->Controls->Add(this->textBox15);
			this->flowLayoutPanel3->Controls->Add(this->comboBox3);
			this->flowLayoutPanel3->Controls->Add(this->textBox17);
			this->flowLayoutPanel3->Controls->Add(this->textBox18);
			this->flowLayoutPanel3->Location = System::Drawing::Point(12, 52);
			this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			this->flowLayoutPanel3->Size = System::Drawing::Size(352, 103);
			this->flowLayoutPanel3->TabIndex = 10;
			// 
			// textBox11
			// 
			this->textBox11->BackColor = System::Drawing::Color::Black;
			this->textBox11->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox11->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->textBox11->Location = System::Drawing::Point(3, 3);
			this->textBox11->Name = L"textBox11";
			this->textBox11->ReadOnly = true;
			this->textBox11->Size = System::Drawing::Size(339, 30);
			this->textBox11->TabIndex = 9;
			this->textBox11->Text = L"General Settings";
			this->textBox11->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox15
			// 
			this->textBox15->BackColor = System::Drawing::Color::MintCream;
			this->textBox15->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox15->Location = System::Drawing::Point(3, 39);
			this->textBox15->Name = L"textBox15";
			this->textBox15->ReadOnly = true;
			this->textBox15->Size = System::Drawing::Size(185, 25);
			this->textBox15->TabIndex = 6;
			this->textBox15->Text = L"Number of Slides:";
			this->textBox15->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// comboBox3
			// 
			this->comboBox3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"2", L"3", L"4" });
			this->comboBox3->Location = System::Drawing::Point(195, 40);
			this->comboBox3->Margin = System::Windows::Forms::Padding(4);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(145, 24);
			this->comboBox3->TabIndex = 3;
			// 
			// textBox17
			// 
			this->textBox17->BackColor = System::Drawing::Color::MintCream;
			this->textBox17->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox17->Location = System::Drawing::Point(3, 71);
			this->textBox17->Name = L"textBox17";
			this->textBox17->ReadOnly = true;
			this->textBox17->Size = System::Drawing::Size(185, 25);
			this->textBox17->TabIndex = 10;
			this->textBox17->Text = L"Time for each Slide (s)";
			this->textBox17->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox18
			// 
			this->textBox18->BackColor = System::Drawing::SystemColors::Info;
			this->textBox18->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox18->Location = System::Drawing::Point(194, 71);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(94, 25);
			this->textBox18->TabIndex = 12;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1049, 549);
			this->Controls->Add(this->flowLayoutPanel3);
			this->Controls->Add(this->flowLayoutPanel2);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->textBox3);
			this->ForeColor = System::Drawing::Color::Black;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1067, 596);
			this->MinimumSize = System::Drawing::Size(1067, 596);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Activated += gcnew System::EventHandler(this, &MyForm::MyForm_Activated);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel2->PerformLayout();
			this->flowLayoutPanel3->ResumeLayout(false);
			this->flowLayoutPanel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Activated(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		//label1->Text = "hi\n";
	}
	
	private: System::Void comboBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		//System::String selectedText 
		//selectedText = comboBox1->GetItemText(comboBox1->SelectedItem);
		//label1->Text = comboBox1->GetItemText;

	}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	auto x = comboBox1->SelectedIndex;
/*	if (x == 0) {
		label1->Text = "Small";
	}
	else if (x == 1) {
		label1->Text = "Medium";
	}
	else if (x == 2) {
		label1->Text = "Large";
	}
*/
	
}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	colorDialog1->ShowDialog();
	textBox1->BackColor = colorDialog1->Color;
}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
public: System::Void textBox3_GotFocus(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox4_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox6_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox7_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

	file.open("C:/Users/brand/OneDrive/UCF/Fall 2018/LED_Matrix/LEDgui/out.txt");
	LED led;
	TextSlide txtSlide;
	led.setNumberOfSlides(comboBox3->SelectedIndex + 1);
	int loopTime = System::Convert::ToInt32(textBox18->Text);
	led.setSecondsToLoop(loopTime);

	msclr::interop::marshal_context context;
	std::string text = context.marshal_as<std::string>(textBox5->Text);
	txtSlide.setText(text);

	std::string textSize = context.marshal_as<std::string>(textBox5->Text);

	System::String^ color = "RGB(" + textBox1->BackColor.R.ToString() + "," + textBox1->BackColor.G.ToString() + "," + textBox1->BackColor.B.ToString() + ")";
	std::string colorString = context.marshal_as<std::string>(color);

	file << led.getNumSlides();
	file << "\n";
	file << led.getLoopTime();
	file << "\n";

	file << text;
	file << "\n";
	file << comboBox1->SelectedIndex;
	file << "\n";
	file << colorString;
	file << "\n";	
	file << comboBox2->SelectedIndex;
	file << "\n";

	file.close();



}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	file.open("C:/Users/brand/OneDrive/UCF/Fall 2018/LED_Matrix/LEDgui/WIFIout.txt");

	msclr::interop::marshal_context context;
	std::string username = context.marshal_as<std::string>(textBox10->Text);
	std::string password = context.marshal_as<std::string>(textBox13->Text);

	file << username;
	file << "\n";
	file << password;
	file << "\n";

	file.close();

}
};
}

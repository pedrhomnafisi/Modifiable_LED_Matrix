#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include "text.h"
#include <cstddef>
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <opencv2/opencv.hpp>


namespace LEDgui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cv;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class LEDMatrix : public System::Windows::Forms::Form
	{
	public:
		LEDMatrix(void)
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
		~LEDMatrix()
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
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label2;


	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox16;
	private: System::Windows::Forms::ComboBox^  comboBox4;
	private: System::Windows::Forms::TextBox^  textBox19;
	private: System::Windows::Forms::ComboBox^  comboBox5;
	private: System::Windows::Forms::TextBox^  textBox20;
	private: System::Windows::Forms::TextBox^  textBox21;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::TextBox^  textBox22;
	private: System::Windows::Forms::TextBox^  textBox23;
	private: System::Windows::Forms::ComboBox^  comboBox6;
	private: System::Windows::Forms::TextBox^  textBox24;
	private: System::Windows::Forms::ComboBox^  comboBox7;
	private: System::Windows::Forms::TextBox^  textBox25;
	private: System::Windows::Forms::TextBox^  textBox26;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::TextBox^  textBox27;
	private: System::Windows::Forms::TextBox^  textBox28;
	private: System::Windows::Forms::ComboBox^  comboBox8;
	private: System::Windows::Forms::TextBox^  textBox29;
	private: System::Windows::Forms::ComboBox^  comboBox9;
	private: System::Windows::Forms::TextBox^  textBox30;
	private: System::Windows::Forms::TextBox^  textBox31;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label5;















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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(LEDMatrix::typeid));
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox24 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox7 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox25 = (gcnew System::Windows::Forms::TextBox());
			this->textBox26 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->textBox27 = (gcnew System::Windows::Forms::TextBox());
			this->textBox28 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox8 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox29 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox9 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox30 = (gcnew System::Windows::Forms::TextBox());
			this->textBox31 = (gcnew System::Windows::Forms::TextBox());
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->flowLayoutPanel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
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
			this->comboBox1->Location = System::Drawing::Point(147, 74);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(110, 21);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->Visible = false;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &LEDMatrix::comboBox1_SelectedIndexChanged);
			this->comboBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &LEDMatrix::comboBox1_MouseClick);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::MintCream;
			this->button2->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(2, 48);
			this->button2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(139, 20);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Choose Text Color:";
			this->button2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &LEDMatrix::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Red;
			this->textBox1->Location = System::Drawing::Point(145, 48);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(62, 20);
			this->textBox1->TabIndex = 5;
			this->textBox1->Visible = false;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::MintCream;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(2, 74);
			this->textBox2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(140, 21);
			this->textBox2->TabIndex = 6;
			this->textBox2->Text = L"Choose Text Size:";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox2->Visible = false;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &LEDMatrix::textBox2_TextChanged);
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
			this->textBox3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(788, 37);
			this->textBox3->TabIndex = 7;
			this->textBox3->TabStop = false;
			this->textBox3->Text = L"LED MATRIX Control System";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox3->Click += gcnew System::EventHandler(this, &LEDMatrix::textBox3_Click);
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &LEDMatrix::textBox3_TextChanged);
			this->textBox3->GotFocus += gcnew System::EventHandler(this, &LEDMatrix::textBox3_GotFocus);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::Transparent;
			this->flowLayoutPanel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->flowLayoutPanel1->Controls->Add(this->textBox7);
			this->flowLayoutPanel1->Controls->Add(this->label2);
			this->flowLayoutPanel1->Controls->Add(this->button2);
			this->flowLayoutPanel1->Controls->Add(this->textBox1);
			this->flowLayoutPanel1->Controls->Add(this->textBox2);
			this->flowLayoutPanel1->Controls->Add(this->comboBox1);
			this->flowLayoutPanel1->Controls->Add(this->textBox6);
			this->flowLayoutPanel1->Controls->Add(this->comboBox2);
			this->flowLayoutPanel1->Controls->Add(this->textBox14);
			this->flowLayoutPanel1->Controls->Add(this->textBox5);
			this->flowLayoutPanel1->Controls->Add(this->label4);
			this->flowLayoutPanel1->Controls->Add(this->button5);
			this->flowLayoutPanel1->Controls->Add(this->textBox4);
			this->flowLayoutPanel1->Controls->Add(this->textBox16);
			this->flowLayoutPanel1->Controls->Add(this->comboBox4);
			this->flowLayoutPanel1->Controls->Add(this->textBox19);
			this->flowLayoutPanel1->Controls->Add(this->comboBox5);
			this->flowLayoutPanel1->Controls->Add(this->textBox20);
			this->flowLayoutPanel1->Controls->Add(this->textBox21);
			this->flowLayoutPanel1->Controls->Add(this->label3);
			this->flowLayoutPanel1->Controls->Add(this->button6);
			this->flowLayoutPanel1->Controls->Add(this->textBox22);
			this->flowLayoutPanel1->Controls->Add(this->textBox23);
			this->flowLayoutPanel1->Controls->Add(this->comboBox6);
			this->flowLayoutPanel1->Controls->Add(this->textBox24);
			this->flowLayoutPanel1->Controls->Add(this->comboBox7);
			this->flowLayoutPanel1->Controls->Add(this->textBox25);
			this->flowLayoutPanel1->Controls->Add(this->textBox26);
			this->flowLayoutPanel1->Controls->Add(this->label5);
			this->flowLayoutPanel1->Controls->Add(this->button7);
			this->flowLayoutPanel1->Controls->Add(this->textBox27);
			this->flowLayoutPanel1->Controls->Add(this->textBox28);
			this->flowLayoutPanel1->Controls->Add(this->comboBox8);
			this->flowLayoutPanel1->Controls->Add(this->textBox29);
			this->flowLayoutPanel1->Controls->Add(this->comboBox9);
			this->flowLayoutPanel1->Controls->Add(this->textBox30);
			this->flowLayoutPanel1->Controls->Add(this->textBox31);
			this->flowLayoutPanel1->Location = System::Drawing::Point(11, 38);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(265, 621);
			this->flowLayoutPanel1->TabIndex = 8;
			// 
			// textBox7
			// 
			this->textBox7->BackColor = System::Drawing::Color::Black;
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox7->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->textBox7->Location = System::Drawing::Point(2, 3);
			this->textBox7->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(255, 26);
			this->textBox7->TabIndex = 9;
			this->textBox7->Text = L"Text Controls";
			this->textBox7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &LEDMatrix::textBox7_TextChanged);
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Heavy", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Tomato;
			this->label2->Location = System::Drawing::Point(3, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(255, 13);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Slide 1";
			this->label2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label2->Visible = false;
			this->label2->Click += gcnew System::EventHandler(this, &LEDMatrix::label2_Click);
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::Color::MintCream;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox6->Location = System::Drawing::Point(2, 101);
			this->textBox6->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(140, 21);
			this->textBox6->TabIndex = 9;
			this->textBox6->Text = L"Choose Text Animation";
			this->textBox6->Visible = false;
			this->textBox6->TextChanged += gcnew System::EventHandler(this, &LEDMatrix::textBox6_TextChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"None", L"Flash", L"Scroll" });
			this->comboBox2->Location = System::Drawing::Point(147, 101);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(110, 21);
			this->comboBox2->TabIndex = 10;
			this->comboBox2->Visible = false;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &LEDMatrix::comboBox2_SelectedIndexChanged);
			// 
			// textBox14
			// 
			this->textBox14->BackColor = System::Drawing::Color::MintCream;
			this->textBox14->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox14->Location = System::Drawing::Point(2, 128);
			this->textBox14->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox14->Name = L"textBox14";
			this->textBox14->ReadOnly = true;
			this->textBox14->Size = System::Drawing::Size(255, 21);
			this->textBox14->TabIndex = 11;
			this->textBox14->Text = L"Insert Text:";
			this->textBox14->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox14->Visible = false;
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::SystemColors::Info;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(2, 155);
			this->textBox5->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(255, 21);
			this->textBox5->TabIndex = 9;
			this->textBox5->Text = L"Default";
			this->textBox5->Visible = false;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Heavy", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Tomato;
			this->label4->Location = System::Drawing::Point(3, 179);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(255, 13);
			this->label4->TabIndex = 36;
			this->label4->Text = L"Slide 2";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label4->Visible = false;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::MintCream;
			this->button5->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(2, 195);
			this->button5->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(139, 20);
			this->button5->TabIndex = 13;
			this->button5->Text = L"Choose Text Color:";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Visible = false;
			this->button5->Click += gcnew System::EventHandler(this, &LEDMatrix::button5_Click_1);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::Red;
			this->textBox4->Location = System::Drawing::Point(145, 195);
			this->textBox4->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(62, 20);
			this->textBox4->TabIndex = 14;
			this->textBox4->Visible = false;
			// 
			// textBox16
			// 
			this->textBox16->BackColor = System::Drawing::Color::MintCream;
			this->textBox16->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox16->Location = System::Drawing::Point(2, 221);
			this->textBox16->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox16->Name = L"textBox16";
			this->textBox16->ReadOnly = true;
			this->textBox16->Size = System::Drawing::Size(140, 21);
			this->textBox16->TabIndex = 15;
			this->textBox16->Text = L"Choose Text Size:";
			this->textBox16->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox16->Visible = false;
			// 
			// comboBox4
			// 
			this->comboBox4->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Small (4 Lines Fit)", L"Medium (2 Lines Fit)",
					L"Large (1 Line Fits)"
			});
			this->comboBox4->Location = System::Drawing::Point(147, 221);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(110, 21);
			this->comboBox4->TabIndex = 12;
			this->comboBox4->Visible = false;
			this->comboBox4->SelectedIndexChanged += gcnew System::EventHandler(this, &LEDMatrix::comboBox4_SelectedIndexChanged);
			// 
			// textBox19
			// 
			this->textBox19->BackColor = System::Drawing::Color::MintCream;
			this->textBox19->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox19->Location = System::Drawing::Point(2, 248);
			this->textBox19->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox19->Name = L"textBox19";
			this->textBox19->ReadOnly = true;
			this->textBox19->Size = System::Drawing::Size(140, 21);
			this->textBox19->TabIndex = 16;
			this->textBox19->Text = L"Choose Text Animation";
			this->textBox19->Visible = false;
			// 
			// comboBox5
			// 
			this->comboBox5->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"None", L"Flash", L"Scroll" });
			this->comboBox5->Location = System::Drawing::Point(147, 248);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(110, 21);
			this->comboBox5->TabIndex = 18;
			this->comboBox5->Visible = false;
			// 
			// textBox20
			// 
			this->textBox20->BackColor = System::Drawing::Color::MintCream;
			this->textBox20->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox20->Location = System::Drawing::Point(2, 275);
			this->textBox20->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox20->Name = L"textBox20";
			this->textBox20->ReadOnly = true;
			this->textBox20->Size = System::Drawing::Size(255, 21);
			this->textBox20->TabIndex = 19;
			this->textBox20->Text = L"Insert Text:";
			this->textBox20->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox20->Visible = false;
			// 
			// textBox21
			// 
			this->textBox21->BackColor = System::Drawing::SystemColors::Info;
			this->textBox21->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox21->Location = System::Drawing::Point(2, 302);
			this->textBox21->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox21->Name = L"textBox21";
			this->textBox21->Size = System::Drawing::Size(255, 21);
			this->textBox21->TabIndex = 17;
			this->textBox21->Text = L"Default";
			this->textBox21->Visible = false;
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Heavy", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Tomato;
			this->label3->Location = System::Drawing::Point(3, 326);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(255, 13);
			this->label3->TabIndex = 37;
			this->label3->Text = L"Slide 3";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label3->Visible = false;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::MintCream;
			this->button6->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(2, 342);
			this->button6->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(139, 20);
			this->button6->TabIndex = 21;
			this->button6->Text = L"Choose Text Color:";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Visible = false;
			this->button6->Click += gcnew System::EventHandler(this, &LEDMatrix::button6_Click);
			// 
			// textBox22
			// 
			this->textBox22->BackColor = System::Drawing::Color::Red;
			this->textBox22->Location = System::Drawing::Point(145, 342);
			this->textBox22->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox22->Name = L"textBox22";
			this->textBox22->ReadOnly = true;
			this->textBox22->Size = System::Drawing::Size(62, 20);
			this->textBox22->TabIndex = 22;
			this->textBox22->Visible = false;
			// 
			// textBox23
			// 
			this->textBox23->BackColor = System::Drawing::Color::MintCream;
			this->textBox23->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox23->Location = System::Drawing::Point(2, 368);
			this->textBox23->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox23->Name = L"textBox23";
			this->textBox23->ReadOnly = true;
			this->textBox23->Size = System::Drawing::Size(140, 21);
			this->textBox23->TabIndex = 23;
			this->textBox23->Text = L"Choose Text Size:";
			this->textBox23->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox23->Visible = false;
			// 
			// comboBox6
			// 
			this->comboBox6->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Small (4 Lines Fit)", L"Medium (2 Lines Fit)",
					L"Large (1 Line Fits)"
			});
			this->comboBox6->Location = System::Drawing::Point(147, 368);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(110, 21);
			this->comboBox6->TabIndex = 20;
			this->comboBox6->Visible = false;
			// 
			// textBox24
			// 
			this->textBox24->BackColor = System::Drawing::Color::MintCream;
			this->textBox24->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox24->Location = System::Drawing::Point(2, 395);
			this->textBox24->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox24->Name = L"textBox24";
			this->textBox24->ReadOnly = true;
			this->textBox24->Size = System::Drawing::Size(140, 21);
			this->textBox24->TabIndex = 24;
			this->textBox24->Text = L"Choose Text Animation";
			this->textBox24->Visible = false;
			// 
			// comboBox7
			// 
			this->comboBox7->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox7->FormattingEnabled = true;
			this->comboBox7->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"None", L"Flash", L"Scroll" });
			this->comboBox7->Location = System::Drawing::Point(147, 395);
			this->comboBox7->Name = L"comboBox7";
			this->comboBox7->Size = System::Drawing::Size(110, 21);
			this->comboBox7->TabIndex = 26;
			this->comboBox7->Visible = false;
			// 
			// textBox25
			// 
			this->textBox25->BackColor = System::Drawing::Color::MintCream;
			this->textBox25->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox25->Location = System::Drawing::Point(2, 422);
			this->textBox25->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox25->Name = L"textBox25";
			this->textBox25->ReadOnly = true;
			this->textBox25->Size = System::Drawing::Size(255, 21);
			this->textBox25->TabIndex = 27;
			this->textBox25->Text = L"Insert Text:";
			this->textBox25->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox25->Visible = false;
			// 
			// textBox26
			// 
			this->textBox26->BackColor = System::Drawing::SystemColors::Info;
			this->textBox26->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox26->Location = System::Drawing::Point(2, 449);
			this->textBox26->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox26->Name = L"textBox26";
			this->textBox26->Size = System::Drawing::Size(255, 21);
			this->textBox26->TabIndex = 25;
			this->textBox26->Text = L"Default";
			this->textBox26->Visible = false;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Heavy", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Tomato;
			this->label5->Location = System::Drawing::Point(3, 473);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(255, 13);
			this->label5->TabIndex = 38;
			this->label5->Text = L"Slide 4";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label5->Visible = false;
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::MintCream;
			this->button7->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(2, 489);
			this->button7->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(139, 20);
			this->button7->TabIndex = 29;
			this->button7->Text = L"Choose Text Color:";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Visible = false;
			this->button7->Click += gcnew System::EventHandler(this, &LEDMatrix::button7_Click);
			// 
			// textBox27
			// 
			this->textBox27->BackColor = System::Drawing::Color::Red;
			this->textBox27->Location = System::Drawing::Point(145, 489);
			this->textBox27->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox27->Name = L"textBox27";
			this->textBox27->ReadOnly = true;
			this->textBox27->Size = System::Drawing::Size(62, 20);
			this->textBox27->TabIndex = 30;
			this->textBox27->Visible = false;
			// 
			// textBox28
			// 
			this->textBox28->BackColor = System::Drawing::Color::MintCream;
			this->textBox28->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox28->Location = System::Drawing::Point(2, 515);
			this->textBox28->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox28->Name = L"textBox28";
			this->textBox28->ReadOnly = true;
			this->textBox28->Size = System::Drawing::Size(140, 21);
			this->textBox28->TabIndex = 31;
			this->textBox28->Text = L"Choose Text Size:";
			this->textBox28->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox28->Visible = false;
			// 
			// comboBox8
			// 
			this->comboBox8->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox8->FormattingEnabled = true;
			this->comboBox8->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"Small (4 Lines Fit)", L"Medium (2 Lines Fit)",
					L"Large (1 Line Fits)"
			});
			this->comboBox8->Location = System::Drawing::Point(147, 515);
			this->comboBox8->Name = L"comboBox8";
			this->comboBox8->Size = System::Drawing::Size(110, 21);
			this->comboBox8->TabIndex = 28;
			this->comboBox8->Visible = false;
			// 
			// textBox29
			// 
			this->textBox29->BackColor = System::Drawing::Color::MintCream;
			this->textBox29->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox29->Location = System::Drawing::Point(2, 542);
			this->textBox29->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox29->Name = L"textBox29";
			this->textBox29->ReadOnly = true;
			this->textBox29->Size = System::Drawing::Size(140, 21);
			this->textBox29->TabIndex = 32;
			this->textBox29->Text = L"Choose Text Animation";
			this->textBox29->Visible = false;
			// 
			// comboBox9
			// 
			this->comboBox9->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox9->FormattingEnabled = true;
			this->comboBox9->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"None", L"Flash", L"Scroll" });
			this->comboBox9->Location = System::Drawing::Point(147, 542);
			this->comboBox9->Name = L"comboBox9";
			this->comboBox9->Size = System::Drawing::Size(110, 21);
			this->comboBox9->TabIndex = 34;
			this->comboBox9->Visible = false;
			// 
			// textBox30
			// 
			this->textBox30->BackColor = System::Drawing::Color::MintCream;
			this->textBox30->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox30->Location = System::Drawing::Point(2, 569);
			this->textBox30->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox30->Name = L"textBox30";
			this->textBox30->ReadOnly = true;
			this->textBox30->Size = System::Drawing::Size(255, 21);
			this->textBox30->TabIndex = 35;
			this->textBox30->Text = L"Insert Text:";
			this->textBox30->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox30->Visible = false;
			// 
			// textBox31
			// 
			this->textBox31->BackColor = System::Drawing::SystemColors::Info;
			this->textBox31->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox31->Location = System::Drawing::Point(2, 596);
			this->textBox31->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox31->Name = L"textBox31";
			this->textBox31->Size = System::Drawing::Size(255, 21);
			this->textBox31->TabIndex = 33;
			this->textBox31->Text = L"Default";
			this->textBox31->Visible = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Chartreuse;
			this->button1->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(223, 657);
			this->button1->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(63, 22);
			this->button1->TabIndex = 9;
			this->button1->Text = L"ENTER";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &LEDMatrix::button1_Click);
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->flowLayoutPanel2->BackColor = System::Drawing::Color::Transparent;
			this->flowLayoutPanel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->flowLayoutPanel2->Controls->Add(this->textBox8);
			this->flowLayoutPanel2->Controls->Add(this->textBox9);
			this->flowLayoutPanel2->Controls->Add(this->textBox10);
			this->flowLayoutPanel2->Controls->Add(this->textBox12);
			this->flowLayoutPanel2->Controls->Add(this->textBox13);
			this->flowLayoutPanel2->Location = System::Drawing::Point(381, 508);
			this->flowLayoutPanel2->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(265, 149);
			this->flowLayoutPanel2->TabIndex = 9;
			this->flowLayoutPanel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &LEDMatrix::flowLayoutPanel2_Paint);
			// 
			// textBox8
			// 
			this->textBox8->BackColor = System::Drawing::Color::Black;
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox8->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->textBox8->Location = System::Drawing::Point(2, 3);
			this->textBox8->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox8->Name = L"textBox8";
			this->textBox8->ReadOnly = true;
			this->textBox8->Size = System::Drawing::Size(255, 26);
			this->textBox8->TabIndex = 9;
			this->textBox8->Text = L"WiFi Settings";
			this->textBox8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox9
			// 
			this->textBox9->BackColor = System::Drawing::Color::MintCream;
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox9->Location = System::Drawing::Point(2, 35);
			this->textBox9->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox9->Name = L"textBox9";
			this->textBox9->ReadOnly = true;
			this->textBox9->Size = System::Drawing::Size(255, 21);
			this->textBox9->TabIndex = 10;
			this->textBox9->Text = L"Insert Network ID:";
			this->textBox9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox10
			// 
			this->textBox10->BackColor = System::Drawing::SystemColors::Info;
			this->textBox10->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox10->Location = System::Drawing::Point(2, 62);
			this->textBox10->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(255, 21);
			this->textBox10->TabIndex = 11;
			this->textBox10->Text = L"Default";
			// 
			// textBox12
			// 
			this->textBox12->BackColor = System::Drawing::Color::MintCream;
			this->textBox12->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox12->Location = System::Drawing::Point(2, 89);
			this->textBox12->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox12->Name = L"textBox12";
			this->textBox12->ReadOnly = true;
			this->textBox12->Size = System::Drawing::Size(255, 21);
			this->textBox12->TabIndex = 9;
			this->textBox12->Text = L"Insert Password:";
			this->textBox12->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox13
			// 
			this->textBox13->BackColor = System::Drawing::SystemColors::Info;
			this->textBox13->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox13->Location = System::Drawing::Point(2, 116);
			this->textBox13->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(255, 21);
			this->textBox13->TabIndex = 9;
			this->textBox13->Text = L"Default";
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Chartreuse;
			this->button4->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(593, 657);
			this->button4->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(63, 22);
			this->button4->TabIndex = 9;
			this->button4->Text = L"ENTER";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &LEDMatrix::button4_Click);
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
			this->flowLayoutPanel3->Location = System::Drawing::Point(377, 38);
			this->flowLayoutPanel3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->flowLayoutPanel3->Name = L"flowLayoutPanel3";
			this->flowLayoutPanel3->Size = System::Drawing::Size(265, 94);
			this->flowLayoutPanel3->TabIndex = 10;
			// 
			// textBox11
			// 
			this->textBox11->BackColor = System::Drawing::Color::Black;
			this->textBox11->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox11->ForeColor = System::Drawing::Color::DeepSkyBlue;
			this->textBox11->Location = System::Drawing::Point(2, 3);
			this->textBox11->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox11->Name = L"textBox11";
			this->textBox11->ReadOnly = true;
			this->textBox11->Size = System::Drawing::Size(255, 26);
			this->textBox11->TabIndex = 9;
			this->textBox11->Text = L"General Settings";
			this->textBox11->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox15
			// 
			this->textBox15->BackColor = System::Drawing::Color::MintCream;
			this->textBox15->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox15->Location = System::Drawing::Point(2, 35);
			this->textBox15->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox15->Name = L"textBox15";
			this->textBox15->ReadOnly = true;
			this->textBox15->Size = System::Drawing::Size(140, 21);
			this->textBox15->TabIndex = 6;
			this->textBox15->Text = L"Number of Slides:";
			this->textBox15->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// comboBox3
			// 
			this->comboBox3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"2", L"3", L"4" });
			this->comboBox3->Location = System::Drawing::Point(147, 35);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(110, 21);
			this->comboBox3->TabIndex = 3;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &LEDMatrix::comboBox3_SelectedIndexChanged);
			// 
			// textBox17
			// 
			this->textBox17->BackColor = System::Drawing::Color::MintCream;
			this->textBox17->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox17->Location = System::Drawing::Point(2, 62);
			this->textBox17->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox17->Name = L"textBox17";
			this->textBox17->ReadOnly = true;
			this->textBox17->Size = System::Drawing::Size(140, 21);
			this->textBox17->TabIndex = 10;
			this->textBox17->Text = L"Time for each Slide (s)";
			this->textBox17->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox18
			// 
			this->textBox18->BackColor = System::Drawing::SystemColors::Info;
			this->textBox18->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox18->Location = System::Drawing::Point(146, 62);
			this->textBox18->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(71, 21);
			this->textBox18->TabIndex = 12;
			this->textBox18->Text = L"15";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Location = System::Drawing::Point(306, 168);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(457, 306);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Tag = L"";
			this->pictureBox1->Click += gcnew System::EventHandler(this, &LEDMatrix::pictureBox1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &LEDMatrix::openFileDialog1_FileOk);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Heavy", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Chartreuse;
			this->label1->Location = System::Drawing::Point(417, 145);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(253, 21);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Click Below to Choose an Image:";
			this->label1->UseMnemonic = false;
			this->label1->Click += gcnew System::EventHandler(this, &LEDMatrix::label1_Click_1);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Chartreuse;
			this->button3->Font = (gcnew System::Drawing::Font(L"Franklin Gothic Medium", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(675, 479);
			this->button3->Margin = System::Windows::Forms::Padding(2, 3, 2, 3);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(63, 22);
			this->button3->TabIndex = 13;
			this->button3->Text = L"ENTER";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &LEDMatrix::button3_Click);
			// 
			// LEDMatrix
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(788, 679);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->flowLayoutPanel3);
			this->Controls->Add(this->flowLayoutPanel2);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->ForeColor = System::Drawing::Color::Black;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(804, 718);
			this->MinimumSize = System::Drawing::Size(804, 718);
			this->Name = L"LEDMatrix";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LEDMatrix";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Activated += gcnew System::EventHandler(this, &LEDMatrix::LEDMatrix_Activated);
			this->Load += gcnew System::EventHandler(this, &LEDMatrix::LEDMatrix_Load);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel2->PerformLayout();
			this->flowLayoutPanel3->ResumeLayout(false);
			this->flowLayoutPanel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void LEDMatrix_Activated(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void LEDMatrix_Load(System::Object^  sender, System::EventArgs^  e) {

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
	System::String^ filepath = System::AppDomain::CurrentDomain->BaseDirectory;

	msclr::interop::marshal_context context1;
	std::string newFilePath = context1.marshal_as<std::string>(filepath);

	file.open(newFilePath + "text.txt");
	LED led;
	TextSlide txtSlide;

	if (comboBox3->SelectedIndex >= 0) {
		if (textBox18->Text == "") {
			textBox18->Text = "15";
		}
		if (textBox5->Text == "") {
			textBox5->Text = "Defaut";
		}
		if (textBox21->Text == "") {
			textBox21->Text = "Defaut";
		}
		if (textBox26->Text == "") {
			textBox26->Text = "Defaut";
		}
		if (textBox31->Text == "") {
			textBox31->Text = "Defaut";
		}
		if (comboBox1->SelectedIndex == -1) {
			comboBox1->SelectedIndex = 0;
		}
		if (comboBox2->SelectedIndex == -1) {
			comboBox2->SelectedIndex = 0;
		}
		if (comboBox4->SelectedIndex == -1) {
			comboBox4->SelectedIndex = 0;
		}
		if (comboBox5->SelectedIndex == -1) {
			comboBox5->SelectedIndex = 0;
		}
		if (comboBox6->SelectedIndex == -1) {
			comboBox6->SelectedIndex = 0;
		}
		if (comboBox7->SelectedIndex == -1) {
			comboBox7->SelectedIndex = 0;
		}
		if (comboBox8->SelectedIndex == -1) {
			comboBox8->SelectedIndex = 0;
		}
		if (comboBox9->SelectedIndex == -1) {
			comboBox9->SelectedIndex = 0;
		}
	}

	led.setNumberOfSlides(comboBox3->SelectedIndex + 1);
	int loopTime = System::Convert::ToInt32(textBox18->Text);
	led.setSecondsToLoop(loopTime);
	
	file << "1";
	file << "~";
	file << led.getNumSlides();
	file << "~";
	file << led.getLoopTime();
	file << "~";

	if (comboBox3->SelectedIndex == 0) {
		msclr::interop::marshal_context context;
		std::string text = context.marshal_as<std::string>(textBox5->Text);
		txtSlide.setText(text);

		System::String^ color = textBox1->BackColor.R.ToString() + " " + textBox1->BackColor.G.ToString() + " " + textBox1->BackColor.B.ToString();
		std::string colorString = context.marshal_as<std::string>(color);

		file << text;
		file << "~";
		file << comboBox1->SelectedIndex;
		file << "~";
		file << colorString;
		file << "~";
		file << comboBox2->SelectedIndex;

		file.close();
	}
	else if (comboBox3->SelectedIndex == 1) {
		msclr::interop::marshal_context context;
		std::string text = context.marshal_as<std::string>(textBox5->Text);
		txtSlide.setText(text);

		System::String^ color = textBox1->BackColor.R.ToString() + " " + textBox1->BackColor.G.ToString() + " " + textBox1->BackColor.B.ToString();
		std::string colorString = context.marshal_as<std::string>(color);

		file << text;
		file << "~";
		file << comboBox1->SelectedIndex;
		file << "~";
		file << colorString;
		file << "~";
		file << comboBox2->SelectedIndex;

		text = context.marshal_as<std::string>(textBox21->Text);
		txtSlide.setText(text);

		color = textBox4->BackColor.R.ToString() + " " + textBox4->BackColor.G.ToString() + " " + textBox4->BackColor.B.ToString();
		colorString = context.marshal_as<std::string>(color);

		file << "~";
		file << text;
		file << "~";
		file << comboBox4->SelectedIndex;
		file << "~";
		file << colorString;
		file << "~";
		file << comboBox5->SelectedIndex;

		file.close();
	}
	else if (comboBox3->SelectedIndex == 2) {
		msclr::interop::marshal_context context;
		std::string text = context.marshal_as<std::string>(textBox5->Text);
		txtSlide.setText(text);

		System::String^ color = textBox1->BackColor.R.ToString() + " " + textBox1->BackColor.G.ToString() + " " + textBox1->BackColor.B.ToString();
		std::string colorString = context.marshal_as<std::string>(color);

		file << text;
		file << "~";
		file << comboBox1->SelectedIndex;
		file << "~";
		file << colorString;
		file << "~";
		file << comboBox2->SelectedIndex;

		text = context.marshal_as<std::string>(textBox21->Text);
		txtSlide.setText(text);

		color = textBox4->BackColor.R.ToString() + " " + textBox4->BackColor.G.ToString() + " " + textBox4->BackColor.B.ToString();
		colorString = context.marshal_as<std::string>(color);

		file << "~";
		file << text;
		file << "~";
		file << comboBox4->SelectedIndex;
		file << "~";
		file << colorString;
		file << "~";
		file << comboBox5->SelectedIndex;

		text = context.marshal_as<std::string>(textBox26->Text);
		txtSlide.setText(text);

		color = textBox22->BackColor.R.ToString() + " " + textBox22->BackColor.G.ToString() + " " + textBox22->BackColor.B.ToString();
		colorString = context.marshal_as<std::string>(color);

		file << "~";
		file << text;
		file << "~";
		file << comboBox6->SelectedIndex;
		file << "~";
		file << colorString;
		file << "~";
		file << comboBox7->SelectedIndex;

		file.close();
	}
	else if (comboBox3->SelectedIndex == 3) {
		msclr::interop::marshal_context context;
		std::string text = context.marshal_as<std::string>(textBox5->Text);
		txtSlide.setText(text);

		System::String^ color = textBox1->BackColor.R.ToString() + " " + textBox1->BackColor.G.ToString() + " " + textBox1->BackColor.B.ToString();
		std::string colorString = context.marshal_as<std::string>(color);

		file << text;
		file << "~";
		file << comboBox1->SelectedIndex;
		file << "~";
		file << colorString;
		file << "~";
		file << comboBox2->SelectedIndex;

		text = context.marshal_as<std::string>(textBox21->Text);
		txtSlide.setText(text);

		color = textBox4->BackColor.R.ToString() + " " + textBox4->BackColor.G.ToString() + " " + textBox4->BackColor.B.ToString();
		colorString = context.marshal_as<std::string>(color);

		file << "~";
		file << text;
		file << "~";
		file << comboBox4->SelectedIndex;
		file << "~";
		file << colorString;
		file << "~";
		file << comboBox5->SelectedIndex;

		text = context.marshal_as<std::string>(textBox26->Text);
		txtSlide.setText(text);

		color = textBox22->BackColor.R.ToString() + " " + textBox22->BackColor.G.ToString() + " " + textBox22->BackColor.B.ToString();
		colorString = context.marshal_as<std::string>(color);

		file << "~";
		file << text;
		file << "~";
		file << comboBox6->SelectedIndex;
		file << "~";
		file << colorString;
		file << "~";
		file << comboBox7->SelectedIndex;

		text = context.marshal_as<std::string>(textBox31->Text);
		txtSlide.setText(text);

		color = textBox27->BackColor.R.ToString() + " " + textBox27->BackColor.G.ToString() + " " + textBox27->BackColor.B.ToString();
		colorString = context.marshal_as<std::string>(color);

		file << "~";
		file << text;
		file << "~";
		file << comboBox8->SelectedIndex;
		file << "~";
		file << colorString;
		file << "~";
		file << comboBox9->SelectedIndex;

		file.close();
	}



}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	System::String^ filepath = System::AppDomain::CurrentDomain->BaseDirectory;
	msclr::interop::marshal_context context1;
	std::string newFilePath = context1.marshal_as<std::string>(filepath);

	file.open(newFilePath + "wifi.txt");

	msclr::interop::marshal_context context;
	std::string username = context.marshal_as<std::string>(textBox10->Text);
	std::string password = context.marshal_as<std::string>(textBox13->Text);

	file << username;
	file << "~";
	file << password;

	file.close();

}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog1->ShowDialog();
	pictureBox1->Image = pictureBox1->Image->FromFile(openFileDialog1->FileName);
	
}

private: System::Void flowLayoutPanel2_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox3_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox3->SelectionStart = textBox3->Text->Length;
}
private: System::Void label1_Click_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	System::String^ filepath = System::AppDomain::CurrentDomain->BaseDirectory;
	msclr::interop::marshal_context context1;
	std::string newFilePath = context1.marshal_as<std::string>(filepath);

	msclr::interop::marshal_context context;
	std::string filename = context.marshal_as<std::string>(openFileDialog1->FileName);
	Mat img = imread(filename);
	//namedWindow("image", WINDOW_NORMAL);
	//imshow("image", img);

	cv::Size s = img.size();
	int height = s.height;
	int width = s.width;

	//textBox10->Text = height.ToString();
	//textBox13->Text = width.ToString();

	int newH, newW;
	double ratioH, ratioW;


	double ratio = (double)width / (double)height;
	// Image fits
	if (height <= 32 && width <= 64) {
		newW = width;
		newH = height;
		ratioH = (double)newH / (double)height;
		ratioW = (double)newW / (double)width;
	}

	// Tall image or Wide image
	else if (height > width || (height < width && (1 / ratio > 0.5))) {
		newH = 32;
		newW = newH * ratio;
		//textBox10->Text = newH.ToString();
		//textBox13->Text = newW.ToString();
		ratioH = (double)newH / (double)height;
		ratioW = (double)newW / (double)width;
	}

	// Wide image
	else if (height < width && (1 / ratio <= 0.5)) {
		newW = 64;
		newH = newW / ratio;
		ratioH = (double)newH / (double)height;
		ratioW = (double)newW / (double)width;
	}

	// Square image
	else {
		newH = 32;
		newW = 32;
		ratioH = (double)newH / (double)height;
		ratioW = (double)newW / (double)width;
	}

	// Print original image.
	//namedWindow("Original picture", WINDOW_NORMAL);
	//imshow("Original picture", img);

	// Resize image and print it.
	cv::Mat resized_img;
	//namedWindow("Floodfill picture", WINDOW_NORMAL);
	resize(img, resized_img, cv::Size(newW, newH), ratioW, ratioH, CV_INTER_LANCZOS4);
	//imshow("Floodfill picture", resized_img);

	cv::Size newS = resized_img.size();

	// Write new dimensions to the file.
	ofstream outfile;
	outfile.open(newFilePath + "image.txt");
	outfile << "2";
	outfile << "~";
	outfile << newS.height;
	outfile << "~";
	outfile << newS.width;
	outfile << "~";

	// Loop through the image matrix and touch each pixel.
	for (int y = 0; y < newH; y++) {
		for (int x = 0; x < newW; x++) {

			Vec3f v = resized_img.at<cv::Vec3b>(y, x);

			// The opencv standard gives the array in BGR format which is why
			// the indices look off.
			float blue = v[0];
			float green = v[1];
			float red = v[2];

			// Write RBG values to the file.
			outfile << red;
			outfile << ",";
			outfile << green;
			outfile << ",";
			outfile << blue;

			// Write '~' instead of ',' to indicate the end of the file.
			if (y == newH - 1 && x == newW - 1) {
			}
			else {
				outfile << ",";
			}
		}
	}

	outfile.close();
		
}
private: System::Void comboBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

	if (comboBox3->SelectedIndex == 0) {
		label2->Visible = true;
		button2->Visible = true;
		textBox1->Visible = true;
		textBox2->Visible = true;
		comboBox1->Visible = true;
		textBox6->Visible = true;
		comboBox2->Visible = true;
		textBox14->Visible = true;
		textBox5->Visible = true;
		button1->Visible = true;

		label4->Visible = false;
		button5->Visible = false;
		textBox4->Visible = false;
		textBox16->Visible = false;
		comboBox4->Visible = false;
		textBox19->Visible = false;
		comboBox5->Visible = false;
		textBox20->Visible = false;
		textBox21->Visible = false;

		label3->Visible = false;
		button6->Visible = false;
		textBox22->Visible = false;
		textBox23->Visible = false;
		comboBox6->Visible = false;
		textBox24->Visible = false;
		comboBox7->Visible = false;
		textBox25->Visible = false;
		textBox26->Visible = false;

		label5->Visible = false;
		button7->Visible = false;
		textBox27->Visible = false;
		textBox28->Visible = false;
		comboBox8->Visible = false;
		textBox29->Visible = false;
		comboBox9->Visible = false;
		textBox30->Visible = false;
		textBox31->Visible = false;
		
	}
	else if (comboBox3->SelectedIndex == 1) {
		label2->Visible = true;
		button2->Visible = true;
		textBox1->Visible = true;
		textBox2->Visible = true;
		comboBox1->Visible = true;
		textBox6->Visible = true;
		comboBox2->Visible = true;
		textBox14->Visible = true;
		textBox5->Visible = true;
		button1->Visible = true;

		label4->Visible = true;
		button5->Visible = true;
		textBox4->Visible = true;
		textBox16->Visible = true;
		comboBox4->Visible = true;
		textBox19->Visible = true;
		comboBox5->Visible = true;
		textBox20->Visible = true;
		textBox21->Visible = true;

		label3->Visible = false;
		button6->Visible = false;
		textBox22->Visible = false;
		textBox23->Visible = false;
		comboBox6->Visible = false;
		textBox24->Visible = false;
		comboBox7->Visible = false;
		textBox25->Visible = false;
		textBox26->Visible = false;

		label5->Visible = false;
		button7->Visible = false;
		textBox27->Visible = false;
		textBox28->Visible = false;
		comboBox8->Visible = false;
		textBox29->Visible = false;
		comboBox9->Visible = false;
		textBox30->Visible = false;
		textBox31->Visible = false;
	}
	else if (comboBox3->SelectedIndex == 2) {
		label2->Visible = true;
		button2->Visible = true;
		textBox1->Visible = true;
		textBox2->Visible = true;
		comboBox1->Visible = true;
		textBox6->Visible = true;
		comboBox2->Visible = true;
		textBox14->Visible = true;
		textBox5->Visible = true;
		button1->Visible = true;

		label4->Visible = true;
		button5->Visible = true;
		textBox4->Visible = true;
		textBox16->Visible = true;
		comboBox4->Visible = true;
		textBox19->Visible = true;
		comboBox5->Visible = true;
		textBox20->Visible = true;
		textBox21->Visible = true;

		label3->Visible = true;
		button6->Visible = true;
		textBox22->Visible = true;
		textBox23->Visible = true;
		comboBox6->Visible = true;
		textBox24->Visible = true;
		comboBox7->Visible = true;
		textBox25->Visible = true;
		textBox26->Visible = true;

		label5->Visible = false;
		button7->Visible = false;
		textBox27->Visible = false;
		textBox28->Visible = false;
		comboBox8->Visible = false;
		textBox29->Visible = false;
		comboBox9->Visible = false;
		textBox30->Visible = false;
		textBox31->Visible = false;
	}
	else {
	label2->Visible = true;
	button2->Visible = true;
	textBox1->Visible = true;
	textBox2->Visible = true;
	comboBox1->Visible = true;
	textBox6->Visible = true;
	comboBox2->Visible = true;
	textBox14->Visible = true;
	textBox5->Visible = true;
	button1->Visible = true;

	label4->Visible = true;
	button5->Visible = true;
	textBox4->Visible = true;
	textBox16->Visible = true;
	comboBox4->Visible = true;
	textBox19->Visible = true;
	comboBox5->Visible = true;
	textBox20->Visible = true;
	textBox21->Visible = true;

	label3->Visible = true;
	button6->Visible = true;
	textBox22->Visible = true;
	textBox23->Visible = true;
	comboBox6->Visible = true;
	textBox24->Visible = true;
	comboBox7->Visible = true;
	textBox25->Visible = true;
	textBox26->Visible = true;

	label5->Visible = true;
	button7->Visible = true;
	textBox27->Visible = true;
	textBox28->Visible = true;
	comboBox8->Visible = true;
	textBox29->Visible = true;
	comboBox9->Visible = true;
	textBox30->Visible = true;
	textBox31->Visible = true;
}

}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button5_Click_1(System::Object^  sender, System::EventArgs^  e) {
	colorDialog1->ShowDialog();
	textBox4->BackColor = colorDialog1->Color;
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	colorDialog1->ShowDialog();
	textBox22->BackColor = colorDialog1->Color;
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	colorDialog1->ShowDialog();
	textBox27->BackColor = colorDialog1->Color;
}
private: System::Void comboBox4_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}

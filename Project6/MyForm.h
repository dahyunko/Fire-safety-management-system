#pragma once
#include "reporter.h"
#include "Schema_Check.h"
#include "Select_Query.h"
#include "Custom_Query.h"
#include "Insert_Query.h"
#include "Update_Query.h"
#include "Delete_Query.h"

namespace Project6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// MyForm에 대한 요약입니다.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:













	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;



	protected:

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label5->Location = System::Drawing::Point(27, 23);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(254, 32);
			this->label5->TabIndex = 14;
			this->label5->Text = L"소방 안전 관리 시스템";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::LightSteelBlue;
			this->button3->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button3->Location = System::Drawing::Point(28, 88);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(150, 150);
			this->button3->TabIndex = 15;
			this->button3->Text = L"Schema Check";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::LightSteelBlue;
			this->button4->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button4->Location = System::Drawing::Point(196, 88);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(150, 150);
			this->button4->TabIndex = 16;
			this->button4->Text = L"Select Query";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::LightSteelBlue;
			this->button5->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button5->Location = System::Drawing::Point(28, 252);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(150, 150);
			this->button5->TabIndex = 17;
			this->button5->Text = L"Insert Query";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::LightSteelBlue;
			this->button6->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button6->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button6->Location = System::Drawing::Point(364, 88);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(150, 150);
			this->button6->TabIndex = 18;
			this->button6->Text = L"Custom Query";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::LightSteelBlue;
			this->button1->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(364, 252);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 150);
			this->button1->TabIndex = 20;
			this->button1->Text = L"Delete Query";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::LightSteelBlue;
			this->button2->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->Location = System::Drawing::Point(196, 252);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 150);
			this->button2->TabIndex = 19;
			this->button2->Text = L"Update Query";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(542, 436);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label5);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	Schema_Check^ schema_check = gcnew Schema_Check();
	schema_check->Show();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	Select_Query^ select_query = gcnew Select_Query();
	select_query->Show();
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	Custom_Query^ custom_query = gcnew Custom_Query();
	custom_query->Show();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	Insert_Query^ insert_query = gcnew Insert_Query();
	insert_query->Show();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Update_Query^ update_query = gcnew Update_Query();
	update_query->Show();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Delete_Query^ delete_query = gcnew Delete_Query();
	delete_query->Show();
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}

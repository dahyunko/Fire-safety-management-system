#pragma once

namespace Project6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// SUD_Query에 대한 요약입니다.
	/// </summary>
	public ref class Insert_Query : public System::Windows::Forms::Form
	{
	public:
		Insert_Query(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//

			comboBox3->Items->Add(1);
			comboBox3->Items->Add(2);
			comboBox3->Items->Add(3);

			//db연결
			String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
			SqlConnection^ connection = gcnew SqlConnection(connString);
			connection->Open();

			String^ sqlQuery = "SELECT firefighter_id, dept_id FROM FIREFIGHTER WHERE dept_id is not null;";
			SqlCommand^ command = gcnew SqlCommand(sqlQuery, connection);
			SqlDataReader^ reader = command->ExecuteReader();

			// comboBox에 id와 dept_id 추가
			while (reader->Read())
			{
				int id = reader->GetInt32(0); // rep_id 컬럼 값
				int dept_id = reader->GetInt32(1); // fire_id 컬럼 값

				// comboBox에 rep_id와 fire_id 추가
				comboBox1->Items->Add(id + " , " + dept_id);
			}
			reader->Close();

			//connection->Close();

			//신고자 화재 정보
			String^ sqlQuery3 = "SELECT fire_id, fire_name FROM FIRE_INFO;";
			command = gcnew SqlCommand(sqlQuery3, connection);
			reader = command->ExecuteReader();

			while (reader->Read())
			{
				int fire_id = reader->GetInt32(0); // rep_id 컬럼 값
				String^ fire_name = reader->GetString(1); // fire_id 컬럼 값

				// comboBox에 rep_id와 fire_id 추가
				comboBox4->Items->Add(fire_id + " , " + fire_name);
			}
			reader->Close();

			String^ sqlQuery4 = "SELECT firefighter_id, name FROM FIREFIGHTER;";
			command = gcnew SqlCommand(sqlQuery4, connection);
			reader = command->ExecuteReader();

			connection->Close();
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Insert_Query()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label4;
	protected:

	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;

	private: System::Windows::Forms::TextBox^ textBox7;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label14;



	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;

private: System::Windows::Forms::Button^ button4;








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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label4->Location = System::Drawing::Point(26, 13);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(119, 25);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Insert Query";
			// 
			// dataGridView2
			// 
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->dataGridView2->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->dataGridView2->BackgroundColor = System::Drawing::SystemColors::ActiveBorder;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView2->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Right;
			this->dataGridView2->Location = System::Drawing::Point(711, 0);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowTemplate->Height = 23;
			this->dataGridView2->Size = System::Drawing::Size(393, 486);
			this->dataGridView2->TabIndex = 21;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(29, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 21);
			this->label1->TabIndex = 22;
			this->label1->Text = L"소방대원 등록";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(50, 85);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 21);
			this->textBox1->TabIndex = 23;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(187, 85);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 21);
			this->textBox2->TabIndex = 24;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(348, 85);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 21);
			this->textBox3->TabIndex = 25;
			this->textBox3->Text = L"ex)01011112222";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label2->Location = System::Drawing::Point(31, 89);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 12);
			this->label2->TabIndex = 27;
			this->label2->Text = L"id";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label3->Location = System::Drawing::Point(154, 89);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(31, 12);
			this->label3->TabIndex = 28;
			this->label3->Text = L"이름";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label5->Location = System::Drawing::Point(291, 89);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(57, 12);
			this->label5->TabIndex = 29;
			this->label5->Text = L"전화번호";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label6->Location = System::Drawing::Point(452, 89);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(48, 12);
			this->label6->TabIndex = 30;
			this->label6->Text = L"상사 id";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(499, 85);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 20);
			this->comboBox1->TabIndex = 31;
			this->comboBox1->Text = L"상사 id, 부서 id";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(624, 84);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 32;
			this->button1->Text = L"등록";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Insert_Query::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(624, 163);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 42;
			this->button2->Text = L"등록";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Insert_Query::button2_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(231, 164);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 21);
			this->textBox4->TabIndex = 36;
			this->textBox4->Text = L"ex)01011112222";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(66, 164);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 21);
			this->textBox5->TabIndex = 35;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label7->Location = System::Drawing::Point(29, 130);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(96, 21);
			this->label7->TabIndex = 33;
			this->label7->Text = L"신고자 등록";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label8->Location = System::Drawing::Point(337, 168);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(31, 12);
			this->label8->TabIndex = 40;
			this->label8->Text = L"주소";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label9->Location = System::Drawing::Point(172, 168);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(57, 12);
			this->label9->TabIndex = 39;
			this->label9->Text = L"전화번호";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label10->Location = System::Drawing::Point(31, 168);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(31, 12);
			this->label10->TabIndex = 38;
			this->label10->Text = L"이름";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(372, 164);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 21);
			this->textBox7->TabIndex = 43;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label13->Location = System::Drawing::Point(29, 208);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(242, 21);
			this->label13->TabIndex = 46;
			this->label13->Text = L"화재 유형에 따른 대응방법 등록";
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(93, 245);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(93, 20);
			this->comboBox4->TabIndex = 69;
			this->comboBox4->Text = L"화재 id, 이름";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label11->Location = System::Drawing::Point(31, 249);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(57, 12);
			this->label11->TabIndex = 68;
			this->label11->Text = L"화재정보";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(257, 245);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(363, 21);
			this->textBox6->TabIndex = 70;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label12->Location = System::Drawing::Point(198, 249);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(57, 12);
			this->label12->TabIndex = 71;
			this->label12->Text = L"대응방법";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(624, 244);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 72;
			this->button3->Text = L"등록";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Insert_Query::button3_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label14->Location = System::Drawing::Point(29, 286);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(80, 21);
			this->label14->TabIndex = 73;
			this->label14->Text = L"부서 등록";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(224, 317);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(51, 20);
			this->comboBox3->TabIndex = 78;
			this->comboBox3->Text = L"ex)1";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(80, 317);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 21);
			this->textBox8->TabIndex = 74;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label16->Location = System::Drawing::Point(185, 321);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(34, 12);
			this->label16->TabIndex = 77;
			this->label16->Text = L"floor";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label17->Location = System::Drawing::Point(31, 321);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(44, 12);
			this->label17->TabIndex = 76;
			this->label17->Text = L"부서명";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(624, 321);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 82;
			this->button4->Text = L"등록";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Insert_Query::button4_Click);
			// 
			// Insert_Query
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(1104, 486);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Name = L"Insert_Query";
			this->Text = L"Insert_Query";
			this->Load += gcnew System::EventHandler(this, &Insert_Query::SUD_Query_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void SUD_Query_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ id = textBox1->Text;
		String^ name = textBox2->Text;
		String^ phone = textBox3->Text;
		
		//상사와 맞는 부서 할당
		String^ str = comboBox1->SelectedItem->ToString();
		array<String^>^ splitId = str->Split();  // 기본적으로 공백을 기준으로 문자열을 분할합니다.
		String^ superior_id = splitId[0];  // 분할된 문자열 중 두 번째 요소를 선택합니다.
		String^ dept_id = splitId[2];  // 분할된 문자열 중 두 번째 요소를 선택합니다.

		// 데이터베이스 쿼리 실행하여 DataGridView에 데이터 표시
		String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
		SqlConnection^ connection = gcnew SqlConnection(connString);
		connection->Open();

		String^ insertQuery = "INSERT INTO FIREFIGHTER (firefighter_id, name, phone, superior_id, dept_id) VALUES (@Id, @name, @phone, @superiorId, @deptId);";
		SqlCommand^ command = gcnew SqlCommand(insertQuery, connection);
		command->Parameters->AddWithValue("@Id", Convert::ToInt32(id));
		command->Parameters->AddWithValue("@name", name);
		command->Parameters->AddWithValue("@phone", phone);
		command->Parameters->AddWithValue("@superiorId", Convert::ToInt32(superior_id));
		command->Parameters->AddWithValue("@deptId", Convert::ToInt32(dept_id));

		//command->ExecuteNonQuery(); // INSERT 실행

		// INSERT 성공 여부 확인
		int rowsAffected = command->ExecuteNonQuery();
		if (rowsAffected > 0)MessageBox::Show("소방대원 INSERT 성공");
		else MessageBox::Show("소방대원 INSERT 실패");

		String^ sqlQuery = "select * from FIREFIGHTER; ";
		SqlCommand^ command1 = gcnew SqlCommand(sqlQuery, connection);

		SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command1);
		DataTable^ dataTable = gcnew DataTable();
		dataAdapter->Fill(dataTable);

		dataGridView2->DataSource = dataTable;

		connection->Close();
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	//신고자 등록
	String^ name = textBox5->Text;
	String^ phone = textBox4->Text;
	String^ address = textBox7->Text;

	// 데이터베이스 쿼리 실행하여 DataGridView에 데이터 표시
	String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
	SqlConnection^ connection = gcnew SqlConnection(connString);
	connection->Open();

	String^ insertQuery = "INSERT INTO REPORTER (rep_name, phone, address) VALUES ( @name, @phone, @address);";
	SqlCommand^ command = gcnew SqlCommand(insertQuery, connection);
	command->Parameters->AddWithValue("@name", name);
	command->Parameters->AddWithValue("@phone", phone);
	command->Parameters->AddWithValue("@address", address);

	// INSERT 성공 여부 확인
	int rowsAffected = command->ExecuteNonQuery();
	if (rowsAffected > 0)MessageBox::Show("신고자 INSERT 성공");
	else MessageBox::Show("신고자 INSERT 실패");

	String^ sqlQuery = "select * from REPORTER; ";
	SqlCommand^ command1 = gcnew SqlCommand(sqlQuery, connection);

	SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command1);
	DataTable^ dataTable = gcnew DataTable();
	dataAdapter->Fill(dataTable);

	dataGridView2->DataSource = dataTable;

	connection->Close();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ texts = textBox6->Text;

	//상사와 맞는 부서 할당
	String^ str = comboBox4->SelectedItem->ToString();
	array<String^>^ splitId = str->Split();
	String^ fire_id = splitId[0];
	
	// 데이터베이스 쿼리 실행하여 DataGridView에 데이터 표시
	String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
	SqlConnection^ connection = gcnew SqlConnection(connString);
	connection->Open();

	String^ insertQuery = "INSERT INTO FIRE_RESPONSE (fire_id,info) VALUES ( @fire_id, @text);";
	SqlCommand^ command = gcnew SqlCommand(insertQuery, connection);
	command->Parameters->AddWithValue("@fire_id", fire_id);
	command->Parameters->AddWithValue("@text", texts);

	// INSERT 성공 여부 확인
	int rowsAffected = command->ExecuteNonQuery();
	if (rowsAffected > 0)MessageBox::Show("fire response INSERT 성공");
	else MessageBox::Show("fire response INSERT 실패");

	String^ sqlQuery = "select * from FIRE_RESPONSE; ";
	SqlCommand^ command1 = gcnew SqlCommand(sqlQuery, connection);

	SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command1);
	DataTable^ dataTable = gcnew DataTable();
	dataAdapter->Fill(dataTable);

	dataGridView2->DataSource = dataTable;

	connection->Close();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ name = textBox8->Text;
	String^ floor = comboBox3->SelectedItem->ToString();

	// 데이터베이스 쿼리 실행하여 DataGridView에 데이터 표시
	String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
	SqlConnection^ connection = gcnew SqlConnection(connString);
	connection->Open();

	String^ updateQuery = "INSERT INTO DEPARTMENT (dept_name, floor) VALUES (@name, @floor)";
	SqlCommand^ command = gcnew SqlCommand(updateQuery, connection);
	command->Parameters->AddWithValue("@floor", Convert::ToInt32(floor));
	command->Parameters->AddWithValue("@name", name);

	// INSERT 성공 여부 확인
	int rowsAffected = command->ExecuteNonQuery();
	if (rowsAffected > 0)MessageBox::Show("신고 INSERT 성공");
	else MessageBox::Show("신고 INSERT 실패");

	String^ sqlQuery = "select * from DEPARTMENT; ";
	SqlCommand^ command1 = gcnew SqlCommand(sqlQuery, connection);

	SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command1);
	DataTable^ dataTable = gcnew DataTable();
	dataAdapter->Fill(dataTable);

	dataGridView2->DataSource = dataTable;

	connection->Close();
}
};
}

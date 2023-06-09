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
	/// Update_query에 대한 요약입니다.
	/// </summary>
	public ref class Update_Query : public System::Windows::Forms::Form
	{
	public:
		Update_Query(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//

			comboBox2->Items->Add(3000);
			comboBox2->Items->Add(3500);
			comboBox2->Items->Add(4000);
			comboBox2->Items->Add(4500);
			comboBox2->Items->Add(5000);

			comboBox3->Items->Add(1);
			comboBox3->Items->Add(2);
			comboBox3->Items->Add(3);
			comboBox3->Items->Add(4);
			comboBox3->Items->Add(5);

			//db연결
			String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
			SqlConnection^ connection = gcnew SqlConnection(connString);
			connection->Open();

			String^ sqlQuery = "SELECT firefighter_id, name FROM FIREFIGHTER;";
			SqlCommand^ command = gcnew SqlCommand(sqlQuery, connection);
			SqlDataReader^ reader = command->ExecuteReader();

			// comboBox에 id와 dept_id 추가
			while (reader->Read())
			{
				int id = reader->GetInt32(0); // rep_id 컬럼 값
				String^ name = reader->GetString(1); // fire_id 컬럼 값

				// comboBox에 rep_id와 fire_id 추가
				comboBox1->Items->Add(id + " , " + name);
			}
			reader->Close();

			//신고자 화재 정보
			String^ sqlQuery2 = "SELECT rep_id, fire_id FROM REPORT;";
			command = gcnew SqlCommand(sqlQuery2, connection);
			reader = command->ExecuteReader();

			while (reader->Read())
			{
				int rep_id = reader->GetInt32(0); // rep_id 컬럼 값
				int fire_id = reader->GetInt32(1); // fire_id 컬럼 값

				// comboBox에 rep_id와 fire_id 추가
				comboBox5->Items->Add(rep_id + " , " + fire_id);
			}
			reader->Close();

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

			String^ sqlQuery4 = "SELECT R.rep_id, R.fire_id FROM REPORT AS R WHERE R.scale*2 > (SELECT COUNT(*) FROM FIREFIGHTER AS F WHERE R.rep_id = F.rep_id AND R.fire_id = F.fire_id); ";
			command = gcnew SqlCommand(sqlQuery4, connection);
			reader = command->ExecuteReader();

			while (reader->Read())
			{
				int rep_id = reader->GetInt32(0); // rep_id 컬럼 값
				int fire_id = reader->GetInt32(1); // fire_id 컬럼 값

				// comboBox에 rep_id와 fire_id 추가
				comboBox7->Items->Add(rep_id + " , " + fire_id);
			}
			reader->Close();

			String^ sqlQuery5 = "SELECT firefighter_id, name FROM FIREFIGHTER WHERE rep_id is null;";
			command = gcnew SqlCommand(sqlQuery5, connection);
			reader = command->ExecuteReader();

			// comboBox에 id와 dept_id 추가
			while (reader->Read())
			{
				int id = reader->GetInt32(0); // rep_id 컬럼 값
				String^ name = reader->GetString(1); // fire_id 컬럼 값

				// comboBox에 rep_id와 fire_id 추가
				comboBox6->Items->Add(id + " , " + name);
			}
			reader->Close();

			String^ sqlQuery6 = "SELECT R.rep_id, R.fire_id FROM REPORT AS R WHERE R.scale*2 = (SELECT COUNT(*) FROM FIREFIGHTER AS F WHERE R.rep_id = F.rep_id AND R.fire_id = F.fire_id);";
			command = gcnew SqlCommand(sqlQuery6, connection);
			reader = command->ExecuteReader();

			// comboBox에 id와 dept_id 추가
			while (reader->Read())
			{
				int id = reader->GetInt32(0); // rep_id 컬럼 값
				int fire_id = reader->GetInt32(1); // fire_id 컬럼 값

				// comboBox에 rep_id와 fire_id 추가
				comboBox8->Items->Add(id + " , " + fire_id);
			}
			reader->Close();

			connection->Close();
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Update_Query()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox4;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox1;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label6;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBox5;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::ComboBox^ comboBox6;
private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::ComboBox^ comboBox7;
private: System::Windows::Forms::Label^ label12;

private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::Button^ button3;
private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::ComboBox^ comboBox8;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Button^ button4;




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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->comboBox7 = (gcnew System::Windows::Forms::ComboBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->comboBox8 = (gcnew System::Windows::Forms::ComboBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(611, 148);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 62;
			this->button2->Text = L"변경";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Update_Query::button2_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(242, 149);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 21);
			this->textBox4->TabIndex = 58;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label7->Location = System::Drawing::Point(16, 125);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(118, 21);
			this->label7->TabIndex = 56;
			this->label7->Text = L"신고 정보 변경";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(351, 153);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(29, 12);
			this->label8->TabIndex = 61;
			this->label8->Text = L"규모";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(204, 153);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(29, 12);
			this->label9->TabIndex = 60;
			this->label9->Text = L"위치";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(18, 153);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(43, 12);
			this->label10->TabIndex = 59;
			this->label10->Text = L"신고 id";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(611, 76);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 55;
			this->button1->Text = L"변경";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Update_Query::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(68, 76);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(144, 20);
			this->comboBox1->TabIndex = 54;
			this->comboBox1->Text = L"id, 이름";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(16, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 21);
			this->label1->TabIndex = 46;
			this->label1->Text = L"소방대원 연봉 조정";
			// 
			// dataGridView2
			// 
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->dataGridView2->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->dataGridView2->BackgroundColor = System::Drawing::SystemColors::ActiveBorder;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView2->DefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Right;
			this->dataGridView2->Location = System::Drawing::Point(711, 0);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowTemplate->Height = 23;
			this->dataGridView2->Size = System::Drawing::Size(393, 486);
			this->dataGridView2->TabIndex = 45;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label4->Location = System::Drawing::Point(13, 13);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(133, 25);
			this->label4->TabIndex = 44;
			this->label4->Text = L"Update Query";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(220, 81);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(29, 12);
			this->label6->TabIndex = 53;
			this->label6->Text = L"금액";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(18, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 12);
			this->label2->TabIndex = 50;
			this->label2->Text = L"id, 이름";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(252, 77);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 20);
			this->comboBox2->TabIndex = 64;
			this->comboBox2->Text = L"ex)1000";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(389, 149);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(51, 20);
			this->comboBox3->TabIndex = 65;
			this->comboBox3->Text = L"ex)1";
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(511, 149);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(93, 20);
			this->comboBox4->TabIndex = 67;
			this->comboBox4->Text = L"화재 id, 이름";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(449, 153);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 12);
			this->label3->TabIndex = 66;
			this->label3->Text = L"화재정보";
			// 
			// comboBox5
			// 
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Location = System::Drawing::Point(67, 149);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(131, 20);
			this->comboBox5->TabIndex = 68;
			this->comboBox5->Text = L"신고자 id, 화재 정보";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label5->Location = System::Drawing::Point(16, 191);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(198, 21);
			this->label5->TabIndex = 69;
			this->label5->Text = L"소방대원 신고에 할당하기";
			// 
			// comboBox6
			// 
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Location = System::Drawing::Point(460, 224);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(144, 20);
			this->comboBox6->TabIndex = 71;
			this->comboBox6->Text = L"id, 이름";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(401, 227);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(53, 12);
			this->label11->TabIndex = 70;
			this->label11->Text = L"소방대원";
			// 
			// comboBox7
			// 
			this->comboBox7->FormattingEnabled = true;
			this->comboBox7->Location = System::Drawing::Point(71, 223);
			this->comboBox7->Name = L"comboBox7";
			this->comboBox7->Size = System::Drawing::Size(131, 20);
			this->comboBox7->TabIndex = 73;
			this->comboBox7->Text = L"신고자 id, 화재 정보";
			this->comboBox7->SelectedIndexChanged += gcnew System::EventHandler(this, &Update_Query::comboBox7_SelectedIndexChanged);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(22, 227);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(43, 12);
			this->label12->TabIndex = 72;
			this->label12->Text = L"신고 id";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(208, 227);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(103, 12);
			this->label13->TabIndex = 74;
			this->label13->Text = L"필요한/ 전체 명수";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(611, 223);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 76;
			this->button3->Text = L"할당하기";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Update_Query::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(317, 222);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(78, 21);
			this->textBox1->TabIndex = 77;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label14->Location = System::Drawing::Point(20, 274);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(312, 21);
			this->label14->TabIndex = 78;
			this->label14->Text = L"소방대원 전부 할당된 신고 완료 처리하기";
			// 
			// comboBox8
			// 
			this->comboBox8->FormattingEnabled = true;
			this->comboBox8->Location = System::Drawing::Point(66, 305);
			this->comboBox8->Name = L"comboBox8";
			this->comboBox8->Size = System::Drawing::Size(131, 20);
			this->comboBox8->TabIndex = 80;
			this->comboBox8->Text = L"신고자 id, 화재 정보";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(22, 309);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(43, 12);
			this->label15->TabIndex = 79;
			this->label15->Text = L"신고 id";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(611, 303);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 81;
			this->button4->Text = L"완료";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Update_Query::button4_Click);
			// 
			// Update_Query
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1104, 486);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->comboBox8);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->comboBox7);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->comboBox6);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBox5);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox2);
			this->Name = L"Update_Query";
			this->Text = L"Update_Query";
			this->Load += gcnew System::EventHandler(this, &Update_Query::Update_Query_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Update_Query_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//연봉 변경
	String^ str = comboBox1->SelectedItem->ToString();
	String^ pay = comboBox2->SelectedItem->ToString();

	array<String^>^ splitId = str->Split();
	String^ id = splitId[0];

	// 데이터베이스 쿼리 실행하여 DataGridView에 데이터 표시
	String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
	SqlConnection^ connection = gcnew SqlConnection(connString);
	connection->Open();

	String^ updateQuery = "UPDATE FIREFIGHTER SET pay = @Pay WHERE firefighter_id = @Id;";
	SqlCommand^ command = gcnew SqlCommand(updateQuery, connection);
	command->Parameters->AddWithValue("@Id", Convert::ToInt32(id));
	command->Parameters->AddWithValue("@Pay", Convert::ToInt32(pay));

	// INSERT 성공 여부 확인
	int rowsAffected = command->ExecuteNonQuery();
	if (rowsAffected > 0)MessageBox::Show("연봉 UPDATE 성공");
	else MessageBox::Show("연봉 UPDATE 실패");

	String^ sqlQuery = "select firefighter_id, name, pay from FIREFIGHTER; ";
	SqlCommand^ command1 = gcnew SqlCommand(sqlQuery, connection);

	SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command1);
	DataTable^ dataTable = gcnew DataTable();
	dataAdapter->Fill(dataTable);

	dataGridView2->DataSource = dataTable;

	connection->Close();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	//신고 변경
	String^ str1 = comboBox5->SelectedItem->ToString();
	String^ scale = comboBox3->SelectedItem->ToString();
	String^ str3 = comboBox4->SelectedItem->ToString();
	String^ location = textBox4->Text;

	array<String^>^ splitId = str1->Split();
	String^ rep_id = splitId[0];
	String^ fire_id = splitId[2];

	array<String^>^ splitId2 = str3->Split();
	String^ fire_info_id = splitId2[0];

	// 데이터베이스 쿼리 실행하여 DataGridView에 데이터 표시
	String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
	SqlConnection^ connection = gcnew SqlConnection(connString);
	connection->Open();

	String^ updateQuery = "UPDATE REPORT SET scale = @scale, location = @location,fire_id = @fireInfoId WHERE rep_id = @repId and fire_id = @fireId;";
	SqlCommand^ command = gcnew SqlCommand(updateQuery, connection);
	command->Parameters->AddWithValue("@repId", Convert::ToInt32(rep_id));
	command->Parameters->AddWithValue("@fireId", Convert::ToInt32(fire_id));
	command->Parameters->AddWithValue("@fireInfoId", Convert::ToInt32(fire_info_id));
	command->Parameters->AddWithValue("@scale", Convert::ToInt32(scale));
	command->Parameters->AddWithValue("@location", location);

	// INSERT 성공 여부 확인
	int rowsAffected = command->ExecuteNonQuery();
	if (rowsAffected > 0)MessageBox::Show("신고 UPDATE 성공");
	else MessageBox::Show("신고 UPDATE 실패");

	String^ sqlQuery = "select * from REPORT; ";
	SqlCommand^ command1 = gcnew SqlCommand(sqlQuery, connection);

	SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command1);
	DataTable^ dataTable = gcnew DataTable();
	dataAdapter->Fill(dataTable);

	dataGridView2->DataSource = dataTable;

	connection->Close();
}

private: System::Void comboBox7_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	String^ str1 = comboBox7->SelectedItem->ToString();

	array<String^>^ splitId = str1->Split();
	String^ rep_id = splitId[0];
	String^ fire_id = splitId[2];

	// 데이터베이스 쿼리 실행하여 DataGridView에 데이터 표시
	String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
	SqlConnection^ connection = gcnew SqlConnection(connString);
	connection->Open();

	String^ updateQuery = "SELECT R.scale*2 , R.scale*2 - COUNT(F.rep_id) FROM FIREFIGHTER AS F, REPORT AS R WHERE R.rep_id = F.rep_id AND R.fire_id = F.fire_id AND R.rep_id = @repId AND R.fire_id = @fireId GROUP BY R.scale";
	SqlCommand^ command = gcnew SqlCommand(updateQuery, connection);
	command->Parameters->AddWithValue("@repId", Convert::ToInt32(rep_id));
	command->Parameters->AddWithValue("@fireId", Convert::ToInt32(fire_id));
	SqlDataReader^ reader = command->ExecuteReader();

	if (reader->Read())
	{
		int num1 = reader->GetInt32(0); // rep_id 컬럼 값
		int num2 = reader->GetInt32(1); // fire_id 컬럼 값

		// comboBox에 rep_id와 fire_id 추가
		textBox1->Text = num2.ToString() + "/ " + num1.ToString();
	}
	else textBox1->Text = "0" ;

	reader->Close();
	connection->Close();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	//신고 변경
	String^ str1 = comboBox7->SelectedItem->ToString();
	String^ str = comboBox6->SelectedItem->ToString();

	array<String^>^ splitId = str1->Split();
	String^ rep_id = splitId[0];
	String^ fire_id = splitId[2];

	array<String^>^ splitId1 = str->Split();
	String^ id = splitId1[0];
	
	// 데이터베이스 쿼리 실행하여 DataGridView에 데이터 표시
	String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
	SqlConnection^ connection = gcnew SqlConnection(connString);
	connection->Open();

	String^ updateQuery = "UPDATE FIREFIGHTER SET fire_id = @fireId , rep_id = @repId WHERE firefighter_id = @firefighterId";
	SqlCommand^ command = gcnew SqlCommand(updateQuery, connection);
	command->Parameters->AddWithValue("@repId", Convert::ToInt32(rep_id));
	command->Parameters->AddWithValue("@fireId", Convert::ToInt32(fire_id));
	command->Parameters->AddWithValue("@firefighterId", Convert::ToInt32(id));

	// INSERT 성공 여부 확인
	int rowsAffected = command->ExecuteNonQuery();
	if (rowsAffected > 0)MessageBox::Show("신고 UPDATE 성공");
	else MessageBox::Show("신고 UPDATE 실패");

	String^ sqlQuery = "select * from FIREFIGHTER; ";
	SqlCommand^ command1 = gcnew SqlCommand(sqlQuery, connection);

	SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command1);
	DataTable^ dataTable = gcnew DataTable();
	dataAdapter->Fill(dataTable);

	dataGridView2->DataSource = dataTable;

	connection->Close();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	//신고 변경
	String^ str1 = comboBox8->SelectedItem->ToString();

	array<String^>^ splitId = str1->Split();
	String^ rep_id = splitId[0];
	String^ fire_id = splitId[2];

	
	// 데이터베이스 쿼리 실행하여 DataGridView에 데이터 표시
	String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
	SqlConnection^ connection = gcnew SqlConnection(connString);
	connection->Open();

	String^ updateQuery = "UPDATE REPORT SET solved = 1 WHERE fire_id = @fireId and rep_id = @repId;";
	SqlCommand^ command = gcnew SqlCommand(updateQuery, connection);
	command->Parameters->AddWithValue("@repId", Convert::ToInt32(rep_id));
	command->Parameters->AddWithValue("@fireId", Convert::ToInt32(fire_id));

	// INSERT 성공 여부 확인
	int rowsAffected = command->ExecuteNonQuery();
	if (rowsAffected > 0)MessageBox::Show("신고 UPDATE 성공");
	else MessageBox::Show("신고 UPDATE 실패");

	String^ sqlQuery = "select * from REPORT where solved = 1;";
	SqlCommand^ command1 = gcnew SqlCommand(sqlQuery, connection);

	SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command1);
	DataTable^ dataTable = gcnew DataTable();
	dataAdapter->Fill(dataTable);

	dataGridView2->DataSource = dataTable;

	connection->Close();
}
};
}

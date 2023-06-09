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
	/// Delete_query에 대한 요약입니다.
	/// </summary>
	public ref class Delete_Query : public System::Windows::Forms::Form
	{
	public:
		Delete_Query(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//

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
				String^ dept_Id = reader->GetString(1); // fire_id 컬럼 값

				// comboBox에 rep_id와 fire_id 추가
				comboBox1->Items->Add(id + " , " + dept_Id);
			}
			reader->Close();

			//신고자 화재 정보
			String^ sqlQuery2 = "SELECT rep_id, fire_id FROM REPORT where solved = 1;";
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

			//부서 번호
			String^ sqlQuery3 = "SELECT dept_id, dept_name from DEPARTMENT;";
			command = gcnew SqlCommand(sqlQuery3, connection);
			reader = command->ExecuteReader();

			while (reader->Read())
			{
				int rep_id = reader->GetInt32(0); // rep_id 컬럼 값
				String^ name = reader->GetString(1); // fire_id 컬럼 값

				// comboBox에 rep_id와 fire_id 추가
				comboBox2->Items->Add(rep_id + " , " + name);
			}
			reader->Close();

			//신고자 화재 정보
			String^ sqlQuery4 = "SELECT fire_id, fire_name FROM FIRE_INFO;";
			command = gcnew SqlCommand(sqlQuery4, connection);
			reader = command->ExecuteReader();

			while (reader->Read())
			{
				int fire_id = reader->GetInt32(0); // rep_id 컬럼 값
				String^ fire_name = reader->GetString(1); // fire_id 컬럼 값

				// comboBox에 rep_id와 fire_id 추가
				comboBox3->Items->Add(fire_id + " , " + fire_name);
			}
			reader->Close();


			connection->Close();
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Delete_Query()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:












	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBox5;



	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::Label^ label7;


	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::ComboBox^ comboBox3;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::ListBox^ listBox1;
private: System::Windows::Forms::Label^ label9;







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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(16, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 21);
			this->label1->TabIndex = 46;
			this->label1->Text = L"소방대원 삭제";
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
			this->dataGridView2->Location = System::Drawing::Point(550, 0);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowTemplate->Height = 23;
			this->dataGridView2->Size = System::Drawing::Size(554, 486);
			this->dataGridView2->TabIndex = 45;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label4->Location = System::Drawing::Point(13, 13);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(127, 25);
			this->label4->TabIndex = 44;
			this->label4->Text = L"Delete Query";
			// 
			// comboBox5
			// 
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Location = System::Drawing::Point(75, 150);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(131, 20);
			this->comboBox5->TabIndex = 83;
			this->comboBox5->Text = L"신고자 id, 화재 정보";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(441, 149);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 78;
			this->button2->Text = L"삭제";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Delete_Query::button2_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label7->Location = System::Drawing::Point(16, 126);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(172, 21);
			this->label7->TabIndex = 73;
			this->label7->Text = L"해결된 신고 정보 삭제";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label10->Location = System::Drawing::Point(18, 154);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(48, 12);
			this->label10->TabIndex = 75;
			this->label10->Text = L"신고 id";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(441, 77);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 72;
			this->button1->Text = L"삭제";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Delete_Query::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(78, 77);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(144, 20);
			this->comboBox1->TabIndex = 71;
			this->comboBox1->Text = L"id, 이름";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label2->Location = System::Drawing::Point(18, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 12);
			this->label2->TabIndex = 69;
			this->label2->Text = L"id, 이름";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"맑은 고딕 Semilight", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label3->Location = System::Drawing::Point(194, 131);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(129, 15);
			this->label3->TabIndex = 84;
			this->label3->Text = L"**solved된 신고만 제공";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label5->Location = System::Drawing::Point(16, 210);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(112, 21);
			this->label5->TabIndex = 85;
			this->label5->Text = L"부서 삭제하기";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label6->Location = System::Drawing::Point(16, 288);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(204, 21);
			this->label6->TabIndex = 86;
			this->label6->Text = L"신고 유형별 대응방안 삭제";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(441, 441);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 88;
			this->button3->Text = L"삭제";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Delete_Query::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(441, 240);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 87;
			this->button4->Text = L"삭제";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Delete_Query::button4_Click);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(83, 241);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(144, 20);
			this->comboBox2->TabIndex = 90;
			this->comboBox2->Text = L"부서 id, 이름";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label8->Location = System::Drawing::Point(18, 245);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(62, 12);
			this->label8->TabIndex = 89;
			this->label8->Text = L"부서 번호";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(89, 322);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(93, 20);
			this->comboBox3->TabIndex = 92;
			this->comboBox3->Text = L"화재 id, 이름";
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &Delete_Query::comboBox3_SelectedIndexChanged);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label15->Location = System::Drawing::Point(22, 326);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(57, 12);
			this->label15->TabIndex = 91;
			this->label15->Text = L"화재정보";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 12;
			this->listBox1->Location = System::Drawing::Point(89, 348);
			this->listBox1->Name = L"listBox1";
			this->listBox1->ScrollAlwaysVisible = true;
			this->listBox1->Size = System::Drawing::Size(427, 88);
			this->listBox1->TabIndex = 93;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label9->Location = System::Drawing::Point(22, 348);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(62, 12);
			this->label9->TabIndex = 94;
			this->label9->Text = L"대응 유형";
			// 
			// Delete_Query
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1104, 486);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->comboBox5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->label4);
			this->Name = L"Delete_Query";
			this->Text = L"Delete_Query";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		//소방대원 삭제

		String^ str = comboBox1->SelectedItem->ToString();

		array<String^>^ splitId = str->Split();
		String^ id = splitId[0];

		// 데이터베이스 쿼리 실행하여 DataGridView에 데이터 표시
		String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
		SqlConnection^ connection = gcnew SqlConnection(connString);
		connection->Open();

		String^ deleteQuery = "DELETE FIREFIGHTER WHERE firefighter_id = @Id;";
		SqlCommand^ command = gcnew SqlCommand(deleteQuery, connection);
		command->Parameters->AddWithValue("@Id", Convert::ToInt32(id));

		int rowsAffected = command->ExecuteNonQuery();
		if (rowsAffected > 0)MessageBox::Show("소방대원 DELETE 성공");
		else MessageBox::Show("소방대원 DELETE 실패");

		String^ sqlQuery = "select * from FIREFIGHTER; ";
		SqlCommand^ command1 = gcnew SqlCommand(sqlQuery, connection);

		SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command1);
		DataTable^ dataTable = gcnew DataTable();
		dataAdapter->Fill(dataTable);

		dataGridView2->DataSource = dataTable;

		connection->Close();
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	//신고 삭제
	String^ str1 = comboBox5->SelectedItem->ToString();
	array<String^>^ splitId = str1->Split();
	String^ rep_id = splitId[0];
	String^ fire_id = splitId[2];

	// 데이터베이스 쿼리 실행하여 DataGridView에 데이터 표시
	String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
	SqlConnection^ connection = gcnew SqlConnection(connString);
	connection->Open();

	String^ deleteQuery = "DELETE REPORT WHERE rep_id = @repId and fire_id = @fireId;";
	SqlCommand^ command = gcnew SqlCommand(deleteQuery, connection);
	command->Parameters->AddWithValue("@repId", Convert::ToInt32(rep_id));
	command->Parameters->AddWithValue("@fireId", Convert::ToInt32(fire_id));
	
	// INSERT 성공 여부 확인
	int rowsAffected = command->ExecuteNonQuery();
	if (rowsAffected > 0)MessageBox::Show("신고 DELETE 성공");
	else MessageBox::Show("신고 DELETE 실패");

	String^ sqlQuery = "select * from REPORT; ";
	SqlCommand^ command1 = gcnew SqlCommand(sqlQuery, connection);

	SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command1);
	DataTable^ dataTable = gcnew DataTable();
	dataAdapter->Fill(dataTable);

	dataGridView2->DataSource = dataTable;

	connection->Close();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ str1 = comboBox2->SelectedItem->ToString();
	array<String^>^ splitId = str1->Split();
	String^ dept_id = splitId[0];

	// 데이터베이스 쿼리 실행하여 DataGridView에 데이터 표시
	String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
	SqlConnection^ connection = gcnew SqlConnection(connString);
	connection->Open();

	String^ deleteQuery = "DELETE DEPARTMENT WHERE dept_id = @deptId;";
	SqlCommand^ command = gcnew SqlCommand(deleteQuery, connection);
	command->Parameters->AddWithValue("@deptId", Convert::ToInt32(dept_id));

	// INSERT 성공 여부 확인
	int rowsAffected = command->ExecuteNonQuery();
	if (rowsAffected > 0)MessageBox::Show("신고 DELETE 성공");
	else MessageBox::Show("신고 DELETE 실패");

	String^ sqlQuery = "select * from DEPARTMENT; ";
	SqlCommand^ command1 = gcnew SqlCommand(sqlQuery, connection);

	SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command1);
	DataTable^ dataTable = gcnew DataTable();
	dataAdapter->Fill(dataTable);

	dataGridView2->DataSource = dataTable;

	connection->Close();
}
private: System::Void comboBox3_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	String^ str1 = comboBox3->SelectedItem->ToString();
	array<String^>^ splitId = str1->Split();
	int rep_id = Convert::ToInt32(splitId[0]);

	// 데이터베이스 쿼리 실행하여 DataGridView에 데이터 표시
	String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
	SqlConnection^ connection = gcnew SqlConnection(connString);
	connection->Open();

	String^ sqlQuery = "select fire_response_id, info from FIRE_RESPONSE where fire_id = "+ rep_id;
	SqlCommand^ command = gcnew SqlCommand(sqlQuery, connection);
	SqlDataReader^ reader = command->ExecuteReader();

	// comboBox에 id와 dept_id 추가
	listBox1->Items->Clear();
	while (reader->Read())
	{
		int id = reader->GetInt32(0); // rep_id 컬럼 값
		String^ info = reader->GetString(1); // fire_id 컬럼 값

		// comboBox에 rep_id와 fire_id 추가
		listBox1->Items->Add(id + " , " + info);
	}
	reader->Close();
	
	connection->Close();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ str1 = listBox1->SelectedItem->ToString();
	array<String^>^ splitId = str1->Split();
	String^ response_id = splitId[0];

	// 데이터베이스 쿼리 실행하여 DataGridView에 데이터 표시
	String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
	SqlConnection^ connection = gcnew SqlConnection(connString);
	connection->Open();

	String^ deleteQuery = "DELETE FIRE_RESPONSE WHERE fire_response_id = @response_id;";
	SqlCommand^ command = gcnew SqlCommand(deleteQuery, connection);
	command->Parameters->AddWithValue("@response_id", Convert::ToInt32(response_id));

	// INSERT 성공 여부 확인
	int rowsAffected = command->ExecuteNonQuery();
	if (rowsAffected > 0)MessageBox::Show("DELETE 성공");
	else MessageBox::Show("DELETE 실패");

	String^ sqlQuery = "select * from FIRE_RESPONSE; ";
	SqlCommand^ command1 = gcnew SqlCommand(sqlQuery, connection);

	SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command1);
	DataTable^ dataTable = gcnew DataTable();
	dataAdapter->Fill(dataTable);

	dataGridView2->DataSource = dataTable;

	connection->Close();
}
};
}

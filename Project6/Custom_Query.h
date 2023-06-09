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
	/// Custom_Query에 대한 요약입니다.
	/// </summary>
	public ref class Custom_Query : public System::Windows::Forms::Form
	{
	public:
		Custom_Query(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//

			comboBox4->Items->Add(1);
			comboBox4->Items->Add(2);
			comboBox4->Items->Add(3);
			comboBox4->Items->Add(4);
			comboBox4->Items->Add(5);

			//db연결
			String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
			SqlConnection^ connection = gcnew SqlConnection(connString);
			connection->Open();

			String^ sqlQuery = "SELECT rep_id, fire_id FROM report;";
			SqlCommand^ command = gcnew SqlCommand(sqlQuery, connection);
			SqlDataReader^ reader = command->ExecuteReader();

			// comboBox에 rep_id와 fire_id 추가
			while (reader->Read())
			{
				int repId = reader->GetInt32(0); // rep_id 컬럼 값
				int fireId = reader->GetInt32(1); // fire_id 컬럼 값

				// comboBox에 rep_id와 fire_id 추가
				comboBox1->Items->Add(repId + " , " + fireId);
			}
			reader->Close();

			String^ sqlQuery2 = "SELECT firefighter_id, name FROM FIREFIGHTER;";
			SqlCommand^ command2 = gcnew SqlCommand(sqlQuery2, connection);
			SqlDataReader^ reader2 = command2->ExecuteReader();

			while (reader2->Read())
			{
				int firefighter_id = reader2->GetInt32(0); // firefighter_id 컬럼 값
				String^ name = reader2->GetString(1); // name 컬럼 값

				comboBox2->Items->Add(firefighter_id + " : " + name);
			}

			reader2->Close();

			//신고자 화재 정보
			String^ sqlQuery4 = "SELECT reporter_id, rep_name FROM REPORTER;";
			command = gcnew SqlCommand(sqlQuery4, connection);
			reader = command->ExecuteReader();

			while (reader->Read())
			{
				int rep_id = reader->GetInt32(0); // rep_id 컬럼 값
				String^ rep_name = reader->GetString(1); // fire_id 컬럼 값

				// comboBox에 rep_id와 fire_id 추가
				comboBox5->Items->Add(rep_id + " , " + rep_name);
			}
			reader->Close();

			//신고자 화재 정보
			String^ sqlQuery5 = "SELECT fire_id, fire_name FROM FIRE_INFO;";
			command = gcnew SqlCommand(sqlQuery5, connection);
			reader = command->ExecuteReader();

			while (reader->Read())
			{
				int fire_id = reader->GetInt32(0); // rep_id 컬럼 값
				String^ fire_name = reader->GetString(1); // fire_id 컬럼 값

				// comboBox에 rep_id와 fire_id 추가
				comboBox3->Items->Add(fire_id + " , " + fire_name);
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
				comboBox6->Items->Add(rep_id + " , " + name);
			}
			reader->Close();

			connection->Close();
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Custom_Query()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label4;
	protected:
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::ComboBox^ comboBox5;
	private: System::Windows::Forms::ComboBox^ comboBox3;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
private: System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::ComboBox^ comboBox6;
private: System::Windows::Forms::Label^ label8;




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
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->comboBox5 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox6 = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label4->Location = System::Drawing::Point(25, 12);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(137, 25);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Custom Query";
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(50, 94);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(187, 29);
			this->comboBox1->TabIndex = 19;
			this->comboBox1->Text = L"신고자 번호, 화재 유형";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Custom_Query::comboBox1_SelectedIndexChanged);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ActiveBorder;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Right;
			this->dataGridView1->Location = System::Drawing::Point(414, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 23;
			this->dataGridView1->Size = System::Drawing::Size(690, 486);
			this->dataGridView1->TabIndex = 18;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label1->Location = System::Drawing::Point(28, 66);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(321, 21);
			this->label1->TabIndex = 21;
			this->label1->Text = L"1. 해당 신고에 할당 된 소방대원 정보 조회";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label3->Location = System::Drawing::Point(28, 210);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 21);
			this->label3->TabIndex = 23;
			this->label3->Text = L"3. 신고하기";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label5->Location = System::Drawing::Point(28, 329);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(280, 42);
			this->label5->TabIndex = 24;
			this->label5->Text = L"4. 연봉이 5000이상 이면서 \r\n현재 활동 중이지 않은 소방대원 조회";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label6->Location = System::Drawing::Point(28, 401);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(239, 21);
			this->label6->TabIndex = 25;
			this->label6->Text = L"5. 부서에 할당된 소방대원 조회";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label2->Location = System::Drawing::Point(28, 138);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(369, 21);
			this->label2->TabIndex = 26;
			this->label2->Text = L"2. 해당 소방대원이 할당된 신고의 반응 유형 조회";
			// 
			// comboBox2
			// 
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 12));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(50, 166);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(187, 29);
			this->comboBox2->TabIndex = 27;
			this->comboBox2->Text = L"소방대원 번호";
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Custom_Query::comboBox2_SelectedIndexChanged);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(324, 293);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 91;
			this->button4->Text = L"등록";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Custom_Query::button4_Click);
			// 
			// comboBox5
			// 
			this->comboBox5->FormattingEnabled = true;
			this->comboBox5->Location = System::Drawing::Point(106, 239);
			this->comboBox5->Name = L"comboBox5";
			this->comboBox5->Size = System::Drawing::Size(131, 20);
			this->comboBox5->TabIndex = 90;
			this->comboBox5->Text = L"신고자 id, 화재 정보";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Location = System::Drawing::Point(306, 239);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(93, 20);
			this->comboBox3->TabIndex = 89;
			this->comboBox3->Text = L"화재 id, 이름";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label15->Location = System::Drawing::Point(245, 243);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(57, 12);
			this->label15->TabIndex = 88;
			this->label15->Text = L"화재정보";
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Location = System::Drawing::Point(237, 275);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(51, 20);
			this->comboBox4->TabIndex = 87;
			this->comboBox4->Text = L"ex)1";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(92, 275);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 21);
			this->textBox8->TabIndex = 83;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label16->Location = System::Drawing::Point(200, 279);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(31, 12);
			this->label16->TabIndex = 86;
			this->label16->Text = L"규모";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label17->Location = System::Drawing::Point(55, 279);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(31, 12);
			this->label17->TabIndex = 85;
			this->label17->Text = L"위치";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label18->Location = System::Drawing::Point(55, 243);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(48, 12);
			this->label18->TabIndex = 84;
			this->label18->Text = L"신고 id";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(324, 348);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 92;
			this->button1->Text = L"조회";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Custom_Query::button1_Click);
			// 
			// comboBox6
			// 
			this->comboBox6->FormattingEnabled = true;
			this->comboBox6->Location = System::Drawing::Point(113, 432);
			this->comboBox6->Name = L"comboBox6";
			this->comboBox6->Size = System::Drawing::Size(144, 20);
			this->comboBox6->TabIndex = 94;
			this->comboBox6->Text = L"부서 id, 이름";
			this->comboBox6->SelectedIndexChanged += gcnew System::EventHandler(this, &Custom_Query::comboBox6_SelectedIndexChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"굴림", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label8->Location = System::Drawing::Point(48, 436);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(62, 12);
			this->label8->TabIndex = 93;
			this->label8->Text = L"부서 번호";
			// 
			// Custom_Query
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1104, 486);
			this->Controls->Add(this->comboBox6);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->comboBox5);
			this->Controls->Add(this->comboBox3);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->comboBox4);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Custom_Query";
			this->Text = L"Custom_Query";
			this->Load += gcnew System::EventHandler(this, &Custom_Query::Custom_Query_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Custom_Query_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	//repId + " , " + fireId);

	String^ id = comboBox1->SelectedItem->ToString();
	array<String^>^ splitId = id->Split();  // 기본적으로 공백을 기준으로 문자열을 분할합니다.
	String^ repId = splitId[0];  // 분할된 문자열 중 두 번째 요소를 선택합니다.
	String^ fireId = splitId[2];  // 분할된 문자열 중 두 번째 요소를 선택합니다.

	// 데이터베이스 쿼리 실행하여 DataGridView에 데이터 표시
	String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
	SqlConnection^ connection = gcnew SqlConnection(connString);
	connection->Open();

	String^ sqlQuery = "select * from firefighter where rep_id = @repId  and fire_id = @fireId;";
	SqlCommand^ command = gcnew SqlCommand(sqlQuery, connection);
	command->Parameters->AddWithValue("@repId", Convert::ToInt32(repId));
	command->Parameters->AddWithValue("@fireId", Convert::ToInt32(fireId));

	SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command);
	DataTable^ dataTable = gcnew DataTable();
	dataAdapter->Fill(dataTable);

	dataGridView1->DataSource = dataTable;

	connection->Close();
}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	String^ id = comboBox2->SelectedItem->ToString();
	array<String^>^ splitId = id->Split();  // 기본적으로 공백을 기준으로 문자열을 분할합니다.
	id = splitId[0];  // 분할된 문자열 중 두 번째 요소를 선택합니다.

	// 데이터베이스 쿼리 실행하여 DataGridView에 데이터 표시
	String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
	SqlConnection^ connection = gcnew SqlConnection(connString);
	connection->Open();

	String^ sqlQuery = "select info from FIRE_RESPONSE where fire_id = (select fire_id from FIREFIGHTER where firefighter_id = @id);";
	SqlCommand^ command = gcnew SqlCommand(sqlQuery, connection);
	command->Parameters->AddWithValue("@id", Convert::ToInt32(id));

	SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command);
	DataTable^ dataTable = gcnew DataTable();
	dataAdapter->Fill(dataTable);

	dataGridView1->DataSource = dataTable;

	connection->Close();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ str1 = comboBox5->SelectedItem->ToString();
	String^ scale = comboBox4->SelectedItem->ToString();
	String^ str3 = comboBox3->SelectedItem->ToString();
	String^ location = textBox8->Text;

	array<String^>^ splitId = str1->Split();
	String^ rep_id = splitId[0];

	array<String^>^ splitId2 = str3->Split();
	String^ fire_info_id = splitId2[0];

	// 데이터베이스 쿼리 실행하여 DataGridView에 데이터 표시
	String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
	SqlConnection^ connection = gcnew SqlConnection(connString);
	connection->Open();

	String^ updateQuery = "INSERT INTO REPORT (rep_id, fire_id, location, scale) VALUES (@repId, @fireId, @location, @scale)";
	SqlCommand^ command = gcnew SqlCommand(updateQuery, connection);
	command->Parameters->AddWithValue("@repId", Convert::ToInt32(rep_id));
	command->Parameters->AddWithValue("@fireId", Convert::ToInt32(fire_info_id));
	command->Parameters->AddWithValue("@scale", Convert::ToInt32(scale));
	command->Parameters->AddWithValue("@location", location);

	// INSERT 성공 여부 확인
	int rowsAffected = command->ExecuteNonQuery();
	if (rowsAffected > 0)MessageBox::Show("신고 INSERT 성공");
	else MessageBox::Show("신고 INSERT 실패");

	String^ sqlQuery = "select * from REPORT; ";
	SqlCommand^ command1 = gcnew SqlCommand(sqlQuery, connection);

	SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command1);
	DataTable^ dataTable = gcnew DataTable();
	dataAdapter->Fill(dataTable);

	dataGridView1->DataSource = dataTable;

	connection->Close();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// 데이터베이스 쿼리 실행하여 DataGridView에 데이터 표시
	String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
	SqlConnection^ connection = gcnew SqlConnection(connString);
	connection->Open();

	String^ sqlQuery = "select * from FIREFIGHTER where pay >=5000 and rep_id is null;";
	SqlCommand^ command = gcnew SqlCommand(sqlQuery, connection);

	SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command);
	DataTable^ dataTable = gcnew DataTable();
	dataAdapter->Fill(dataTable);

	dataGridView1->DataSource = dataTable;

	connection->Close();
}
private: System::Void comboBox6_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	String^ str1 = comboBox6->SelectedItem->ToString();
	array<String^>^ splitId = str1->Split();
	int dept_id = Convert::ToInt32(splitId[0]);

	// 데이터베이스 쿼리 실행하여 DataGridView에 데이터 표시
	String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
	SqlConnection^ connection = gcnew SqlConnection(connString);
	connection->Open();

	String^ sqlQuery = "select * from FIREFIGHTER where dept_id="+ dept_id;
	SqlCommand^ command = gcnew SqlCommand(sqlQuery, connection);

	SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command);
	DataTable^ dataTable = gcnew DataTable();
	dataAdapter->Fill(dataTable);

	dataGridView1->DataSource = dataTable;

	connection->Close();
}
};
}

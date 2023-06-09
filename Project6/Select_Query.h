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
	/// Select_Query에 대한 요약입니다.
	/// </summary>
	public ref class Select_Query : public System::Windows::Forms::Form
	{
	public:
		Select_Query(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			
			//--전체 테이블 명 저장
			//불 유형 정보
			comboBox1->Items->Add("select FI.fire_id, FI.fire_name, FR.fire_response_id, FR.info from FIRE_INFO as FI, FIRE_RESPONSE AS FR WHERE FI.fire_id = FR.fire_id;");
			//해당 부서에 할당된 소방대원 명수
			comboBox1->Items->Add("SELECT dp.dept_id, dp.dept_name, dp.floor, COUNT(*) AS include_people FROM DEPARTMENT AS dp, FIREFIGHTER AS ff WHERE dp.dept_id = ff.dept_id GROUP BY dp.dept_id, dp.dept_name, dp.floor;");
			//소방대원의 pay가 4000이상 5000이하
			comboBox1->Items->Add("select * from FIREFIGHTER where pay <= 5000 and pay >= 4000;");
			//서울시에 사는 신고자
			comboBox1->Items->Add("SELECT * FROM REPORTER WHERE address LIKE '%서울시%';");
			//규모가 2이상인 신고
			comboBox1->Items->Add("SELECT * FROM REPORT WHERE scale in (2, 4, 5);");
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Select_Query()
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label4->Location = System::Drawing::Point(25, 21);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(122, 25);
			this->label4->TabIndex = 20;
			this->label4->Text = L"Query Select";
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"맑은 고딕", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(153, 18);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(635, 33);
			this->comboBox1->TabIndex = 19;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Select_Query::comboBox1_SelectedIndexChanged);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
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
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->dataGridView1->Location = System::Drawing::Point(0, 84);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 23;
			this->dataGridView1->Size = System::Drawing::Size(830, 402);
			this->dataGridView1->TabIndex = 18;
			// 
			// Select_Query
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(830, 486);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Select_Query";
			this->Text = L"Select_Query";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		// 선택한 항목 가져오기
		String^ selectedQuery = comboBox1->SelectedItem->ToString();

		// 데이터베이스 쿼리 실행하여 DataGridView에 데이터 표시
		String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
		SqlConnection^ connection = gcnew SqlConnection(connString);
		connection->Open();

		String^ sqlQuery = selectedQuery; // 필요한 경우 테이블 이름과 열 이름을 적절히 변경해주세요.
		SqlCommand^ command = gcnew SqlCommand(sqlQuery, connection);

		SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command);
		DataTable^ dataTable = gcnew DataTable();
		dataAdapter->Fill(dataTable);

		dataGridView1->DataSource = dataTable;

		connection->Close();
	}
};
}

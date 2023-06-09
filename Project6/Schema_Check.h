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
	/// MyForm1�� ���� ����Դϴ�.
	/// </summary>
	public ref class Schema_Check : public System::Windows::Forms::Form
	{
	public:
		Schema_Check(void)
		{
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//

			//��ü ���̺� �� ����
			comboBox1->Items->Add("DEPARTMENT");
			comboBox1->Items->Add("FIRE_INFO");
			comboBox1->Items->Add("FIRE_RESPONSE");
			comboBox1->Items->Add("FIREFIGHTER");
			comboBox1->Items->Add("REPORT");
			comboBox1->Items->Add("REPORTER");
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~Schema_Check()
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
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�. 
		/// �� �޼����� ������ �ڵ� ������� �������� ������.
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
			this->label4->Font = (gcnew System::Drawing::Font(L"���� ���", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->label4->Location = System::Drawing::Point(25, 24);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(159, 25);
			this->label4->TabIndex = 17;
			this->label4->Text = L"��ü ���̺� ��ȸ";
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"���� ���", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(213, 24);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(201, 33);
			this->comboBox1->TabIndex = 16;
			this->comboBox1->Text = L"schema info";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Schema_Check::comboBox1_SelectedIndexChanged);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ActiveBorder;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"����", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->dataGridView1->TabIndex = 15;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Schema_Check::dataGridView1_CellContentClick);
			// 
			// Schema_Check
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(830, 486);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Schema_Check";
			this->Text = L"MyForm1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	// ������ �׸� ��������
	String^ selectedValue = comboBox1->SelectedItem->ToString();

	// �����ͺ��̽� ���� �����Ͽ� DataGridView�� ������ ǥ��
	String^ connString = "Data Source=LAPTOP-CJEKH138\\DBSERVER1;Initial Catalog=COMPANY;User ID=KIM;Password=1234";
	SqlConnection^ connection = gcnew SqlConnection(connString);
	connection->Open();

	//String^ sqlQuery = "SELECT * FROM " + selectedValue; // �ʿ��� ��� ���̺� �̸��� �� �̸��� ������ �������ּ���.
	String^ sqlQuery = "SELECT * FROM information_schema.COLUMNS WHERE TABLE_NAME = '"+ selectedValue+ "'";
	SqlCommand^ command = gcnew SqlCommand(sqlQuery, connection);

	SqlDataAdapter^ dataAdapter = gcnew SqlDataAdapter(command);
	DataTable^ dataTable = gcnew DataTable();
	dataAdapter->Fill(dataTable);

	dataGridView1->DataSource = dataTable;

	connection->Close();
}
};
}

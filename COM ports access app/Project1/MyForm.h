#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			findPorts();
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
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::Label^ label3;
	private: System::IO::Ports::SerialPort^ serialPort1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label4;

	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(410, 29);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 0;
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"4800", L"9600", L"14400", L"19200", L"38400",
					L"57600"
			});
			this->comboBox2->Location = System::Drawing::Point(410, 81);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 24);
			this->comboBox2->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(328, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"COM Ports";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(329, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(75, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Baud Rate";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(352, 156);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(78, 41);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Init port";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(449, 155);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(82, 42);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Close port";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(59, 29);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(172, 22);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"Recieve";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(59, 77);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(172, 22);
			this->textBox2->TabIndex = 7;
			this->textBox2->Text = L"Enter";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(59, 129);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Send";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(156, 128);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Read";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(12, 191);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(261, 23);
			this->progressBar1->TabIndex = 10;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 168);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(87, 17);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Port status";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(279, 191);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(57, 23);
			this->button5->TabIndex = 12;
			this->button5->Text = L"+10";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(266, 171);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(80, 17);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Test button";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(543, 226);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Name = L"MyForm";
			this->Text = L" ";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		// Find available Ports --------------------------------------
	private: void findPorts(void)
	{
		// get Ports names
		array<Object^>^ objectArray = SerialPort::GetPortNames();
		// add string arrau to combobox
		this->comboBox1->Items->AddRange(objectArray);
	}


		   // Init button ---------------------------------------
	  private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	  {
		  this->textBox1->Text = String::Empty;
		  if (this->comboBox1->Text == String::Empty || this->comboBox2->Text == String::Empty)
			  this->textBox1->Text = "Please Select Port Settings";
		  else
		  {
			  try
			  {
				  // make sure port isn't open  
				  if (!this->serialPort1->IsOpen)
				  {
					  this->serialPort1->PortName = this->comboBox1->Text;
					  //this->textBox1->Text=this->comboBox1->Text;
					  this->serialPort1->BaudRate = Int32::Parse(this->comboBox2->Text);
					  //this->textBox1->Text=this->comboBox2->Text;
					  this->textBox2->Text = "Enter Message Here";
					  //open serial port 
					  this->serialPort1->Open();
					  this->progressBar1->Value = 100;
				  }
				  else
					  this->textBox2->Text = "Port isn't openned";
			  }
			  catch (UnauthorizedAccessException^)
			  {
				  this->textBox2->Text = "UnauthorizedAccess";
			  }
		  }
	  }

			 // Close port button -------------------------------------------
  private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
  {
	  //close serialPort
	  this->serialPort1->Close();
	  // update progress bar
	  this->progressBar1->Value = 0;
	  // Enable read button
	  this->button4->Enabled = true;
	  // Enable the init button
	  this->button1->Enabled = true;
  }

		 // Send button --------------------------------------
  private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
  {
	  // add sender name 
	  String^ name = this->serialPort1->PortName;
	  // grab text and store in send buffer
	  String^ message = this->textBox2->Text;
	  // write to serial
	  if (this->serialPort1->IsOpen)
		  //this->_serialPort->WriteLine(String::Format("<{0}>: {1}",name,message));
		  this->serialPort1->WriteLine(message);
	  else
		  this->textBox2->Text = "Port Not Opened";
  }


		 // Read button --------------------------------------
//this will start the asyn for backgroundwork
  private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
  {

	  // check if port is ready for reading
	  if (this->serialPort1->IsOpen)
	  {
		  // Reset the text in the result label.
		  this->textBox1->Text = String::Empty;

		  // this will read manually
		  try {
			  this->textBox1->Text = this->serialPort1->ReadLine();
		  }
		  catch (TimeoutException^)
		  {
			  this->textBox1->Text = "Timeout Exception";
		  }

		  // Disable the init button
		  // the asynchronous operation is done.
		  this->button1->Enabled = false;
	  }
	  else
		  // give error warning
		  this->textBox1->Text = "Port Not Opened";
  }
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {

	this->progressBar1->Value += 10;

	if (progressBar1->Value == 100)
	{
		this->button5->Enabled = false;
	}


}
};
}

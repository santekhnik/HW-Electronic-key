#pragma once
 // SERIALPORT_H

void hello();
void portCommunicate(char* port);
void stm_cmd_2(char* port);
void stm_cmd_3(char* port);
void stm_cmd_4(char* port);
void stm_cmd_5(char* port);

//void key_update(string key);

namespace Project1 {
	
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::Runtime::InteropServices;
	using namespace System::Data::SqlClient;
	using namespace System::IO;

	/////////////////////////
	
	
	
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

	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;

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
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(411, 30);
			this->comboBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
			this->comboBox2->Location = System::Drawing::Point(411, 81);
			this->comboBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 24);
			this->comboBox2->TabIndex = 1;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(328, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"COM Ports";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(329, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Baud Rate";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(352, 156);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(77, 41);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Init port";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(449, 155);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(83, 42);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Close port";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(59, 30);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(172, 22);
			this->textBox1->TabIndex = 6;
			this->textBox1->Text = L"Recieve";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(59, 78);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(172, 22);
			this->textBox2->TabIndex = 7;
			this->textBox2->Text = L"Enter";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(68, 128);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Send";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(156, 128);
			this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Read";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(12, 191);
			this->progressBar1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(261, 23);
			this->progressBar1->TabIndex = 10;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(12, 167);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(80, 16);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Port status";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(279, 191);
			this->button5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
			this->label4->Location = System::Drawing::Point(267, 171);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(73, 16);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Test button";
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(337, 313);
			this->button7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(92, 41);
			this->button7->TabIndex = 15;
			this->button7->Text = L"Cancel";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->Location = System::Drawing::Point(436, 314);
			this->button8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(97, 41);
			this->button8->TabIndex = 16;
			this->button8->Text = L"Reset key";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(17, 292);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(119, 16);
			this->label5->TabIndex = 17;
			this->label5->Text = L"Keys management";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(163, 283);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(369, 22);
			this->textBox3->TabIndex = 18;
			this->textBox3->Text = L"Enter key";
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(163, 313);
			this->button6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(111, 41);
			this->button6->TabIndex = 19;
			this->button6->Text = L"Update";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(12, 219);
			this->button9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(189, 23);
			this->button9->TabIndex = 20;
			this->button9->Text = L"Check connection";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(207, 219);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(94, 23);
			this->button10->TabIndex = 21;
			this->button10->Text = L"KEY number";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(307, 219);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(75, 23);
			this->button11->TabIndex = 22;
			this->button11->Text = L"KEY ID";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(388, 219);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(63, 23);
			this->button12->TabIndex = 23;
			this->button12->Text = L"Encrypt";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(456, 219);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(75, 23);
			this->button13->TabIndex = 24;
			this->button13->Text = L"Decrypt";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(543, 368);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
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
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
	  ComboBox comboBox1;
	  /////////////////////////
	  portCommunicate("\\\\.\\COM6");


	  /////////////////////////
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
	   int baudRate = 4800;
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	ComboBox comboBox2;
	
	switch (comboBox2.SelectedIndex) {
	case 0:
		baudRate = 4800;
		break;
	case 1:
		baudRate = 9600;
		break;
	case 2:
		baudRate = 14400;
		break;
	case 3:
		baudRate = 19200;
		break;
	case 4:
		baudRate = 38400;
		break;
	case 5:
		baudRate = 57600;
		break;
	default:
		baudRate = 9600;
	} 
	
}
	   

/*
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	//TextBox textBox3;
	//textBox3.Text;
		StreamWriter^ sw = gcnew StreamWriter("D:\\cpp\\keys.txt", true);
		sw->Write(textBox3->Text);
		sw->Close();

} */
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ sr = "D:\\cpp\\keys.txt";
	StreamReader^ file;
	File^ temp;
	if (temp->Exists("D:\\cpp\\keys.txt")) {
		file = File::OpenText(sr);
		textBox3->Text = file->ReadToEnd();
		file->Close();
	}
	else {
		textBox3->Text = "00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00";
	}
	
	/*fin.open("example.txt");
	ofstream temp;
	temp.open("temp.txt");
	cout << "Which line do you want to remove? ";
	cin >> deleteline; */
}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
	hello();
	String^ sr = "D:\\cpp\\keys.txt";
	File^ file;
	file->Delete("D:\\cpp\\keys.txt");
	StreamWriter^ sw = gcnew StreamWriter("D:\\cpp\\keys.txt", true);
	sw->Write(textBox3->Text);
	sw->Close();
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	//key_update(textBox3->Text);
}



private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
	portCommunicate("\\\\.\\COM6");
}

private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
	stm_cmd_3("\\\\.\\COM6");
}
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
	stm_cmd_2("\\\\.\\COM6");
}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	stm_cmd_4("\\\\.\\COM6");
}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
	 stm_cmd_5("\\\\.\\COM6");

}
};
}

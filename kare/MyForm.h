#include <math.h>
#include <string>
char tr[50] = { 0 };
char LL[100] = {0};

#include <vector>

using namespace std;
vector <int> class_ids = vector<int>();

namespace kare {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	private:
		bool load_new = true;
		int break_point=0;
		Point startPos;
		Point currentPos;
		System::String^ path;
		int W, H;
		int class_count=0;
		//int* classes;
		//Color* renkler;
		int* renkler;
		bool drawing;
		List<Rectangle> myRectangles;// = new List<Rectangle>();
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::ColorDialog^ colorDialog1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button4;



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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1196, 15);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Load";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1138, 726);
			this->panel1->TabIndex = 4;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Cross;
			this->pictureBox1->Location = System::Drawing::Point(3, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 50);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseDown);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1321, 15);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Save";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(1343, 69);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 7;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(1237, 69);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1156, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Add Class";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(1216, 71);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 9;
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(1470, 69);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(20, 23);
			this->button3->TabIndex = 10;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(1168, 115);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(322, 589);
			this->listBox1->TabIndex = 11;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(1237, 710);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(161, 23);
			this->button4->TabIndex = 12;
			this->button4->Text = L"DeleteSelectedRect";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1498, 750);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int min(int a, int b) {
			//a < b ?return b : a;
			if (a < b)return a;
			if (a > b) return b;
		}
	bool file_exist(char* filename)
		{
			struct stat   buffer;
			return (stat(filename, &buffer) == 0);
	}
	
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		class_ids.clear();
		myRectangles.Clear();
		comboBox1->Items->Clear();
		//comboBox1->Items->Add("adem");
		OpenFileDialog^ a = gcnew OpenFileDialog();
		a->Title = "Resim YUKE";
		a->Filter = "ne istersen(*.* | *.*";
		if (a->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			pictureBox1->Image = gcnew Bitmap(a->FileName);
			
			path = a->FileName;
			int t = path->Length;
			W = pictureBox1->Width;
			H = pictureBox1->Height;
			//int s = pictureBox1->Width;
		//	//path[t] = 'x';

		path = path->Remove((t-3),3);
		path = System::String::Concat(path, "txt");
		sprintf(tr, "%s", path);
		if (file_exist(tr)) {
			load_new = false;
			checkBox1->Checked = true;
		//	label1->Text = "asd a";
			FILE* koordinatlar = fopen(tr, "r");
			
			
			int cs_id;
			float x_c, y_c, i_w, i_h;
		//	comboBox1->Items->Add("sinif " + 0);
			while (fscanf(koordinatlar,"%d %f %f %f %f\n",&cs_id,&x_c,&y_c,&i_w,&i_h)!=EOF)
			{
				//bir kereye 
				if (cs_id > class_count)class_count = cs_id;
				int w = (i_w * W);
				int h = (i_h * H);
				int x = x_c * W - w/ 2;
				int y = y_c * H - h / 2;
				//Rectan
				myRectangles.Add(Rectangle(x, y, w, h));
				class_ids.push_back(cs_id);
				listBox1->Items->Add("Class id::" + cs_id + "  X::" + x + "  Y::" + y + "  Width::" + w + "  Heihgt::" + h);

		
				
			}
			//label3->Text = "" + class_count;
			for (int i = 0; i < class_count+1; i++)
			{
				comboBox1->Items->Add("sinif " + i);
			}
			
			fclose(koordinatlar);
			renkler = new int[3 * class_count+1];
			for (int i = 0; i < 3 * (class_count+1); i++)
			{
				renkler[i] = 0;
			}

		}
		else {
			

			String^ s = "Etiketlenmemiþ bir resim!\n Etiket dosyasý oluþturuluyor";
			MessageBox::Show(s);
		}
		

		}
	}
		   

		    Rectangle getRectangle()
		   {
			   
			   return   Rectangle(
				   min(startPos.X, currentPos.X),
				   min(startPos.Y, currentPos.Y),
					fabs(startPos.X - currentPos.X),
				   fabs(startPos.Y - currentPos.Y));
		   }





	private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Graphics^ kp = pictureBox1->CreateGraphics();
		Pen^ X = gcnew Pen(Color::Red, 2);



		if (!drawing)
		{
			pictureBox1->Refresh();

			kp->DrawLine(X, 0, currentPos.Y, W, currentPos.Y);
			kp->DrawLine(X, currentPos.X, 0, currentPos.X, H);
		}
		currentPos = e->Location;
		if (drawing) {
			pictureBox1->Invalidate();
			
		}
	}
private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left)
	{
		currentPos = startPos = e->Location;
		drawing = true;
	}
}
private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (drawing)
	{
		if (comboBox1->SelectedIndex == -1)
		{
			String^ s = "Lütfen sýnýf Seçiniz";
			MessageBox::Show(s);

		}
		drawing = false;
		Rectangle rect = getRectangle();
		if (rect.Width > 0 && rect.Height > 0 && comboBox1->SelectedIndex>=0) {
			myRectangles.Add(rect);
			
			class_ids.push_back((int)comboBox1->SelectedIndex);
			listBox1->Items->Add("Class id::"+(int)comboBox1->SelectedIndex+ "  X::" + rect.X + "  Y::" + rect.Y + "  Width::" + rect.Width + "  Heihgt::" + rect.Height);
			
		}
		listBox1->Update();
		pictureBox1->Invalidate();
	}
}
	   //int W = 500;
	   //int H = 500;
	   int count = 0;
private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Pen^ eksen = gcnew Pen(Color::Black, 2);
	//Pen^ eksen = gcnew Pen(Color::Black, 2);
	if (myRectangles.Count > 0) {
		//e->Graphics->DrawRectangles(eksen, myRectangles.ToArray());
		//int selected = 0;
		for each (Rectangle a in myRectangles) {
			int id = class_ids.at(count);
			if (count == (int)listBox1->SelectedIndex) {
				eksen->Color = Color::FromArgb(255,255,255);

			}
			else {
				eksen->Color = Color::FromArgb(renkler[id * 3 + 0], renkler[id * 3 + 1], renkler[id * 3 + 2]);
			}
			e->Graphics->DrawRectangle(eksen, a);
			//label2->Text =""+ a.X;
		//	int a = listBox1->SelectedIndex;
			count++;
			
		}
	}
	count = 0;
	eksen->Color = Color::Black;
	if (drawing)
	{
		e->Graphics->DrawRectangle(eksen, getRectangle());
		


	}
}


private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	FILE* f = fopen(tr, "w");
	int count = 0;
	int id;
	float x, y, x_w, y_h;
	for each (Rectangle a in myRectangles) {
		 id = class_ids.at(count);
		 x = (float)a.X;
		 y = (float)a.Y;
		 x_w = (float)a.Width;
		 y_h = (float)a.Height;
		 x = (x + x_w / 2) / W;
		 y = (y + y_h / 2) / H;
		 x_w = x_w / W;
		 y_h = y_h / H;
		 fprintf(f, "%d %f %f %f %f\n", id, x, y, x_w, y_h);
		
		count++;
	}
	//fprintf(f, "deneme");
	
	fclose(f);


}

private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

	if (e->KeyChar == (char)Keys::Enter) {
		///label1->Text = "enter basildi";
		comboBox1->Items->Add(textBox1->Text);
		class_count++;

		textBox1->Text = "";
	}



}
private: System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	//label1->Text = "" + comboBox1->SelectedIndex;
	if (checkBox1->Checked)
	{
		//if (break_point == 1)continue;
		textBox1->Visible = false;
		//renkler = new Color[class_count];
		if (load_new) {
			while (break_point < 1) {
				renkler = new int[3 * class_count];
				for (int i = 0; i < 3 * class_count; i++)
				{
					renkler[i] = 0;
				}
				break_point = 1;
			}
		}
	}
	if (!checkBox1->Checked)
	{
		textBox1->Visible = true;
		
	}
	if (comboBox1->SelectedIndex != -1) {
		int a = comboBox1->SelectedIndex;
		button3->BackColor = Color::FromArgb(renkler[a*3+0], renkler[a * 3 + 1], renkler[a * 3 + 2]);
	}


}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	ColorDialog^ cd = gcnew ColorDialog();
	if(cd->ShowDialog() == System::Windows::Forms::DialogResult::OK){
		Color c = cd->Color;
		int a = comboBox1->SelectedIndex;
		if (a!=-1)
		{
			renkler[a * 3 + 0] = (int)c.R;
			renkler[a * 3 + 1] = (int)c.G;
			renkler[a * 3 + 2] = (int)c.B;
		}
		button3->BackColor = c;
	
	}
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ a =  listBox1->SelectedItem->ToString();
	sprintf(LL, "%s", a);
	int x,b,c,d,f;
//("Class id::" + (int)comboBox1->SelectedIndex + "  X::" + rect.X + "  Y::" + rect.Y + "  Width::" + rect.Width + "  Heihgt::" + rect.Height);

	sscanf(LL, "Class id::%d  X::%d  Y::%d  Width::%d  Heihgt::%d", &x,&b,&c,&d,&f);
	//label1->Text = "" + x + ""+b;
	myRectangles.Remove(Rectangle(b, c, d, f));
	listBox1->Items->RemoveAt((int)listBox1->SelectedIndex);
	//Remove calýþýyor eski datayý güncelemede indexler tutmuyor basit bir hata sonra halledilir.
}
};
}

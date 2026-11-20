#pragma once

#include <msclr/marshal_cppstd.h>
#include <iostream>
#include "Boyer.h"

namespace lab10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	//функція для кодування
	string toUtf8(String^ s) {
		cli::array<Byte>^ bytes = System::Text::Encoding::GetEncoding(1251)->GetBytes(s);
		string result;
		result.reserve(bytes->Length);
		for (int i = 0; i < bytes->Length; i++) {
			result += (char)bytes[i];
		}
		return result;
	}

	//інша функція для кодування
	String^ fromUtf8(const string& s) {
		cli::array<Byte>^ bytes = gcnew cli::array<Byte>((int)s.size());
		for (int i = 0; i < (int)s.size(); i++) {
			bytes[i] = (unsigned char)s[i];
		}
		return System::Text::Encoding::GetEncoding(1251)->GetString(bytes);
	}

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			object = new Boyer_Moore;
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
			object = nullptr;
		}
	private: Boyer_Moore* object;
	private: System::Windows::Forms::Label^ EnterTextLabel;
	protected:
	private: System::Windows::Forms::TextBox^ EnterTextTextBox;
	private: System::Windows::Forms::TextBox^ ResultTextBox;
	private: System::Windows::Forms::Label^ ResultLabel;
	private: System::Windows::Forms::Button^ FindPatternButton;

	private: System::Windows::Forms::Label^ EnterPatterLabel;
	private: System::Windows::Forms::TextBox^ EnterPatternTextBox;
	private: System::Windows::Forms::Button^ DisplayTextButton;

	private:
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
			this->EnterTextLabel = (gcnew System::Windows::Forms::Label());
			this->EnterTextTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ResultTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ResultLabel = (gcnew System::Windows::Forms::Label());
			this->FindPatternButton = (gcnew System::Windows::Forms::Button());
			this->EnterPatterLabel = (gcnew System::Windows::Forms::Label());
			this->EnterPatternTextBox = (gcnew System::Windows::Forms::TextBox());
			this->DisplayTextButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// EnterTextLabel
			// 
			this->EnterTextLabel->AutoSize = true;
			this->EnterTextLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EnterTextLabel->Location = System::Drawing::Point(27, 35);
			this->EnterTextLabel->Name = L"EnterTextLabel";
			this->EnterTextLabel->Size = System::Drawing::Size(175, 29);
			this->EnterTextLabel->TabIndex = 0;
			this->EnterTextLabel->Text = L"Введіть текст:";
			// 
			// EnterTextTextBox
			// 
			this->EnterTextTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EnterTextTextBox->Location = System::Drawing::Point(32, 84);
			this->EnterTextTextBox->Multiline = true;
			this->EnterTextTextBox->Name = L"EnterTextTextBox";
			this->EnterTextTextBox->Size = System::Drawing::Size(429, 300);
			this->EnterTextTextBox->TabIndex = 1;
			// 
			// ResultTextBox
			// 
			this->ResultTextBox->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ResultTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ResultTextBox->Location = System::Drawing::Point(517, 84);
			this->ResultTextBox->Multiline = true;
			this->ResultTextBox->Name = L"ResultTextBox";
			this->ResultTextBox->ReadOnly = true;
			this->ResultTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->ResultTextBox->Size = System::Drawing::Size(429, 300);
			this->ResultTextBox->TabIndex = 2;
			this->ResultTextBox->TextChanged += gcnew System::EventHandler(this, &MyForm::ResultTextBox_TextChanged);
			// 
			// ResultLabel
			// 
			this->ResultLabel->AutoSize = true;
			this->ResultLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ResultLabel->Location = System::Drawing::Point(517, 42);
			this->ResultLabel->Name = L"ResultLabel";
			this->ResultLabel->Size = System::Drawing::Size(138, 29);
			this->ResultLabel->TabIndex = 3;
			this->ResultLabel->Text = L"Результат:";
			// 
			// FindPatternButton
			// 
			this->FindPatternButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FindPatternButton->Location = System::Drawing::Point(32, 523);
			this->FindPatternButton->Name = L"FindPatternButton";
			this->FindPatternButton->Size = System::Drawing::Size(342, 50);
			this->FindPatternButton->TabIndex = 4;
			this->FindPatternButton->Text = L"Знайти слово";
			this->FindPatternButton->UseVisualStyleBackColor = true;
			this->FindPatternButton->Click += gcnew System::EventHandler(this, &MyForm::FindPatternButton_Click);
			// 
			// EnterPatterLabel
			// 
			this->EnterPatterLabel->AutoSize = true;
			this->EnterPatterLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EnterPatterLabel->Location = System::Drawing::Point(27, 410);
			this->EnterPatterLabel->Name = L"EnterPatterLabel";
			this->EnterPatterLabel->Size = System::Drawing::Size(181, 29);
			this->EnterPatterLabel->TabIndex = 5;
			this->EnterPatterLabel->Text = L"Введіть слово:";
			// 
			// EnterPatternTextBox
			// 
			this->EnterPatternTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->EnterPatternTextBox->Location = System::Drawing::Point(32, 464);
			this->EnterPatternTextBox->Name = L"EnterPatternTextBox";
			this->EnterPatternTextBox->Size = System::Drawing::Size(342, 35);
			this->EnterPatternTextBox->TabIndex = 6;
			// 
			// DisplayTextButton
			// 
			this->DisplayTextButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DisplayTextButton->Location = System::Drawing::Point(517, 523);
			this->DisplayTextButton->Name = L"DisplayTextButton";
			this->DisplayTextButton->Size = System::Drawing::Size(342, 50);
			this->DisplayTextButton->TabIndex = 7;
			this->DisplayTextButton->Text = L"Вивести текст";
			this->DisplayTextButton->UseVisualStyleBackColor = true;
			this->DisplayTextButton->Click += gcnew System::EventHandler(this, &MyForm::DisplayTextButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(967, 604);
			this->Controls->Add(this->DisplayTextButton);
			this->Controls->Add(this->EnterPatternTextBox);
			this->Controls->Add(this->EnterPatterLabel);
			this->Controls->Add(this->FindPatternButton);
			this->Controls->Add(this->ResultLabel);
			this->Controls->Add(this->ResultTextBox);
			this->Controls->Add(this->EnterTextTextBox);
			this->Controls->Add(this->EnterTextLabel);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void ResultTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		
	}

	private: System::Void FindPatternButton_Click(System::Object^ sender, System::EventArgs^ e) {
		ResultTextBox->Clear();

		string text = toUtf8(EnterTextTextBox->Text);
		string pattern = toUtf8(EnterPatternTextBox->Text);

		if (!object->createObject(text, pattern)) {
			MessageBox::Show(L"Введіть текст і шукане слово.", L"Помилка");
			return;
		}

		ResultTextBox->Text = "Текст: " + Environment::NewLine + fromUtf8(object->getText()) + Environment::NewLine +
			"Шукане слово: " + fromUtf8(object->getPattern()) + Environment::NewLine +
			"Індекси: ";

		vector<int> result = object->search();

		if (result.empty()) { ResultTextBox->Text += "Немає збігів"; }

		for (int i = 0; i < result.size();i++) {
			ResultTextBox->Text += result[i] + " ";
		}

		ResultTextBox->Text += Environment::NewLine + "Стоп-символи: " + Environment::NewLine;

		vector<Boyer_Moore::StopInfo> stop_symbol = object->getStops();

		for (int i = 0;i <(int)stop_symbol.size();i++) {
			Boyer_Moore::StopInfo info = stop_symbol[i];
			String^ symbol = fromUtf8(std::string(1, info.stop_sign));

			ResultTextBox->Text += "'" + symbol + "' текст: " + info.textPos.ToString() +
				" слово: " + info.patternPos.ToString() + " зсув: " + info.shift.ToString() + Environment::NewLine;
		}
	}
private: System::Void DisplayTextButton_Click(System::Object^ sender, System::EventArgs^ e) {
	ResultTextBox->Clear();

	if (object->getText().empty()) {
		MessageBox::Show("Введіть текст","Помилка");
		return;
	}


	ResultTextBox->Text += "Текст: " + Environment::NewLine + fromUtf8(object->getText());

}
};
}

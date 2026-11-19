#pragma once

namespace lab10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
			this->ResultTextBox->Size = System::Drawing::Size(429, 300);
			this->ResultTextBox->TabIndex = 2;
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
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(958, 604);
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
	};
}

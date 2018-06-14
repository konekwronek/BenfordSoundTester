#pragma once
			Plik PlikTestowy;
			TableFile pliczek(10000);
			Dane ObservedData[16];
			Dane ConvertedData, * SelectedData;
			double * TeoreticDistribution;
			Dane ObservedDistribution;
			Tester MainTester;
			Konwerter Converti;
			long n, start, end;
			long double TestResult;
			bool file_opened;
			bool b_PartsDivision;
			long divider;
			int channel;
			streaminfo fileinfo;

namespace BenfordSoundTester {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openWaveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fileInfoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  statisticsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  chiSqareDistributionTestToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  chiSquareDigitsTestToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  distributionParametersToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  meter1ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  channelsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripComboBox^  selectChannelToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  conversionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  divideByPartNumberToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  divideByFreqnecyHzToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  mnimizeNumberOfObservationsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clearAllDivisionsToolStripMenuItem;
	private: System::Windows::Forms::RichTextBox^  MainTextBox;
	private: System::Windows::Forms::OpenFileDialog^  OpenFileDialog;

	private: System::Windows::Forms::StatusStrip^  Status;
	private: System::Windows::Forms::ToolStripStatusLabel^  Label;
	private: System::Windows::Forms::ToolStripTextBox^  Divide;

	private: System::Windows::Forms::ToolStripMenuItem^  divideToolStripMenuItem;
	private: System::Windows::Forms::ToolStripComboBox^  Divide1;

	private: System::Windows::Forms::ToolStripMenuItem^  divideToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripComboBox^  Minimize;

	private: System::Windows::Forms::ToolStripMenuItem^  minimizeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  infoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  createdByKonradWroñskiToolStripMenuItem;



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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openWaveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fileInfoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statisticsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->chiSqareDistributionTestToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->chiSquareDigitsTestToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->meter1ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->distributionParametersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->channelsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->selectChannelToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->conversionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->divideByPartNumberToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Divide = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->divideToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->divideByFreqnecyHzToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Divide1 = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->divideToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnimizeNumberOfObservationsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Minimize = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->minimizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearAllDivisionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->infoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->createdByKonradWroñskiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MainTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->OpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->Status = (gcnew System::Windows::Forms::StatusStrip());
			this->Label = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->menuStrip1->SuspendLayout();
			this->Status->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->fileToolStripMenuItem, 
				this->statisticsToolStripMenuItem, this->channelsToolStripMenuItem, this->conversionsToolStripMenuItem, this->infoToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(539, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->openWaveToolStripMenuItem, 
				this->fileInfoToolStripMenuItem, this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(34, 20);
			this->fileToolStripMenuItem->Text = L"Plik";
			// 
			// openWaveToolStripMenuItem
			// 
			this->openWaveToolStripMenuItem->Name = L"openWaveToolStripMenuItem";
			this->openWaveToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->openWaveToolStripMenuItem->Text = L"Otwórz wave...";
			this->openWaveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openWaveToolStripMenuItem_Click);
			// 
			// fileInfoToolStripMenuItem
			// 
			this->fileInfoToolStripMenuItem->Name = L"fileInfoToolStripMenuItem";
			this->fileInfoToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->fileInfoToolStripMenuItem->Text = L"Informacja o pliku";
			this->fileInfoToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::fileInfoToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->exitToolStripMenuItem->Text = L"Zakoñcz";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// statisticsToolStripMenuItem
			// 
			this->statisticsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->chiSqareDistributionTestToolStripMenuItem, 
				this->chiSquareDigitsTestToolStripMenuItem, this->meter1ToolStripMenuItem, this->distributionParametersToolStripMenuItem});
			this->statisticsToolStripMenuItem->Name = L"statisticsToolStripMenuItem";
			this->statisticsToolStripMenuItem->Size = System::Drawing::Size(67, 20);
			this->statisticsToolStripMenuItem->Text = L"Statystyki";
			// 
			// chiSqareDistributionTestToolStripMenuItem
			// 
			this->chiSqareDistributionTestToolStripMenuItem->Name = L"chiSqareDistributionTestToolStripMenuItem";
			this->chiSqareDistributionTestToolStripMenuItem->Size = System::Drawing::Size(388, 22);
			this->chiSqareDistributionTestToolStripMenuItem->Text = L"Test zgodnoœci chi2 z rozk³adem Benforda";
			this->chiSqareDistributionTestToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::chiSqareDistributionTestToolStripMenuItem_Click);
			// 
			// chiSquareDigitsTestToolStripMenuItem
			// 
			this->chiSquareDigitsTestToolStripMenuItem->Name = L"chiSquareDigitsTestToolStripMenuItem";
			this->chiSquareDigitsTestToolStripMenuItem->Size = System::Drawing::Size(388, 22);
			this->chiSquareDigitsTestToolStripMenuItem->Text = L"Test zgodnoœci chi2 poszczególnych cyfr z rozk³adem Benforda ";
			this->chiSquareDigitsTestToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::chiSquareDigitsTestToolStripMenuItem_Click);
			// 
			// meter1ToolStripMenuItem
			// 
			this->meter1ToolStripMenuItem->Name = L"meter1ToolStripMenuItem";
			this->meter1ToolStripMenuItem->Size = System::Drawing::Size(388, 22);
			this->meter1ToolStripMenuItem->Text = L"Miernik 1 dla rozk³adu Benforda ";
			this->meter1ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::meter1ToolStripMenuItem_Click);
			// 
			// distributionParametersToolStripMenuItem
			// 
			this->distributionParametersToolStripMenuItem->Name = L"distributionParametersToolStripMenuItem";
			this->distributionParametersToolStripMenuItem->Size = System::Drawing::Size(388, 22);
			this->distributionParametersToolStripMenuItem->Text = L"Parametry rozk³adu";
			this->distributionParametersToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::distributionParametersToolStripMenuItem_Click);
			// 
			// channelsToolStripMenuItem
			// 
			this->channelsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->selectChannelToolStripMenuItem});
			this->channelsToolStripMenuItem->Name = L"channelsToolStripMenuItem";
			this->channelsToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->channelsToolStripMenuItem->Text = L"Wybór kana³ów";
			// 
			// selectChannelToolStripMenuItem
			// 
			this->selectChannelToolStripMenuItem->Name = L"selectChannelToolStripMenuItem";
			this->selectChannelToolStripMenuItem->Size = System::Drawing::Size(152, 21);
			this->selectChannelToolStripMenuItem->Text = L"Brak kana³ów";
			// 
			// conversionsToolStripMenuItem
			// 
			this->conversionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->divideByPartNumberToolStripMenuItem, 
				this->divideByFreqnecyHzToolStripMenuItem, this->mnimizeNumberOfObservationsToolStripMenuItem, this->clearAllDivisionsToolStripMenuItem});
			this->conversionsToolStripMenuItem->Name = L"conversionsToolStripMenuItem";
			this->conversionsToolStripMenuItem->Size = System::Drawing::Size(69, 20);
			this->conversionsToolStripMenuItem->Text = L"Konwersje";
			// 
			// divideByPartNumberToolStripMenuItem
			// 
			this->divideByPartNumberToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->Divide, 
				this->divideToolStripMenuItem});
			this->divideByPartNumberToolStripMenuItem->Name = L"divideByPartNumberToolStripMenuItem";
			this->divideByPartNumberToolStripMenuItem->Size = System::Drawing::Size(246, 22);
			this->divideByPartNumberToolStripMenuItem->Text = L"Podziel na okreœlon¹ liczbê czêœci:";
			// 
			// Divide
			// 
			this->Divide->Name = L"Divide";
			this->Divide->Size = System::Drawing::Size(152, 21);
			this->Divide->Text = L"500";
			// 
			// divideToolStripMenuItem
			// 
			this->divideToolStripMenuItem->Name = L"divideToolStripMenuItem";
			this->divideToolStripMenuItem->Size = System::Drawing::Size(212, 22);
			this->divideToolStripMenuItem->Text = L"Podziel";
			this->divideToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::divideToolStripMenuItem_Click);
			// 
			// divideByFreqnecyHzToolStripMenuItem
			// 
			this->divideByFreqnecyHzToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->Divide1, 
				this->divideToolStripMenuItem1});
			this->divideByFreqnecyHzToolStripMenuItem->Name = L"divideByFreqnecyHzToolStripMenuItem";
			this->divideByFreqnecyHzToolStripMenuItem->Size = System::Drawing::Size(246, 22);
			this->divideByFreqnecyHzToolStripMenuItem->Text = L"Podziel przez czêstotliwoœæ (Hz):";
			this->divideByFreqnecyHzToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::divideByFreqnecyHzToolStripMenuItem_Click);
			// 
			// Divide1
			// 
			this->Divide1->Name = L"Divide1";
			this->Divide1->Size = System::Drawing::Size(152, 21);
			this->Divide1->Text = L"1000";
			// 
			// divideToolStripMenuItem1
			// 
			this->divideToolStripMenuItem1->Name = L"divideToolStripMenuItem1";
			this->divideToolStripMenuItem1->Size = System::Drawing::Size(212, 22);
			this->divideToolStripMenuItem1->Text = L"Podziel";
			this->divideToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::divideToolStripMenuItem1_Click);
			// 
			// mnimizeNumberOfObservationsToolStripMenuItem
			// 
			this->mnimizeNumberOfObservationsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->Minimize, 
				this->minimizeToolStripMenuItem});
			this->mnimizeNumberOfObservationsToolStripMenuItem->Name = L"mnimizeNumberOfObservationsToolStripMenuItem";
			this->mnimizeNumberOfObservationsToolStripMenuItem->Size = System::Drawing::Size(246, 22);
			this->mnimizeNumberOfObservationsToolStripMenuItem->Text = L"Minimalizuj liczbê obserwacji";
			// 
			// Minimize
			// 
			this->Minimize->Name = L"Minimize";
			this->Minimize->Size = System::Drawing::Size(152, 21);
			this->Minimize->Text = L"500";
			// 
			// minimizeToolStripMenuItem
			// 
			this->minimizeToolStripMenuItem->Name = L"minimizeToolStripMenuItem";
			this->minimizeToolStripMenuItem->Size = System::Drawing::Size(212, 22);
			this->minimizeToolStripMenuItem->Text = L"Minimalizuj";
			this->minimizeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::minimizeToolStripMenuItem_Click);
			// 
			// clearAllDivisionsToolStripMenuItem
			// 
			this->clearAllDivisionsToolStripMenuItem->Name = L"clearAllDivisionsToolStripMenuItem";
			this->clearAllDivisionsToolStripMenuItem->Size = System::Drawing::Size(246, 22);
			this->clearAllDivisionsToolStripMenuItem->Text = L"Wyczyœæ wszystkie podzia³y";
			this->clearAllDivisionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::clearAllDivisionsToolStripMenuItem_Click);
			// 
			// infoToolStripMenuItem
			// 
			this->infoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->createdByKonradWroñskiToolStripMenuItem});
			this->infoToolStripMenuItem->Name = L"infoToolStripMenuItem";
			this->infoToolStripMenuItem->Size = System::Drawing::Size(71, 20);
			this->infoToolStripMenuItem->Text = L"Informacja";
			// 
			// createdByKonradWroñskiToolStripMenuItem
			// 
			this->createdByKonradWroñskiToolStripMenuItem->Name = L"createdByKonradWroñskiToolStripMenuItem";
			this->createdByKonradWroñskiToolStripMenuItem->Size = System::Drawing::Size(449, 22);
			this->createdByKonradWroñskiToolStripMenuItem->Text = L"Ten program jest typu freeware i zosta³ stworzony prze Konrad Wroñskiego";
			this->createdByKonradWroñskiToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::createdByKonradWroñskiToolStripMenuItem_Click);
			// 
			// MainTextBox
			// 
			this->MainTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->MainTextBox->Location = System::Drawing::Point(0, 27);
			this->MainTextBox->Name = L"MainTextBox";
			this->MainTextBox->Size = System::Drawing::Size(539, 212);
			this->MainTextBox->TabIndex = 1;
			this->MainTextBox->Text = L"";
			// 
			// OpenFileDialog
			// 
			this->OpenFileDialog->Filter = L"Wave files|*.wav|All files|*.*";
			// 
			// Status
			// 
			this->Status->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->Label});
			this->Status->Location = System::Drawing::Point(0, 239);
			this->Status->Name = L"Status";
			this->Status->Size = System::Drawing::Size(539, 22);
			this->Status->TabIndex = 2;
			// 
			// Label
			// 
			this->Label->Name = L"Label";
			this->Label->Size = System::Drawing::Size(38, 17);
			this->Label->Text = L"Ready";
			this->Label->Click += gcnew System::EventHandler(this, &Form1::toolStripStatusLabel1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(539, 261);
			this->Controls->Add(this->Status);
			this->Controls->Add(this->MainTextBox);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Benford Sound Tester pl 1.0 (Ctrl+C aby skopiowaæ)";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->Status->ResumeLayout(false);
			this->Status->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void openWaveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				  file_opened = false;
				 Status->Items["Label"]->Text = "Trwa otwieranie pliku...";
				 if ( OpenFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				 {
					divider = 1;
					for(int i = 0; i<16; i++)
					{
						ObservedData[i].UsunBufor();
					}
					if(PlikTestowy.odczytaj_caly2(OpenFileDialog->FileName, pliczek, fileinfo)==1){
						
						Converti.UstawKanalyWave(ObservedData, fileinfo);
						
						Converti.WaveNaDane(pliczek, ObservedData, fileinfo);

						TeoreticDistribution = new double[9];

						MainTester.GenerujRozkladBenforda(TeoreticDistribution, 9);

						ObservedDistribution.ZmienRozmiar(10);

						Status->Items["Label"]->Text = "Plik " + OpenFileDialog->FileName + " zosta³ pomyœlnie otwarty.";
						file_opened = true;

						selectChannelToolStripMenuItem->Items->Clear();
						for(int i = 1; i <= fileinfo.number_of_channels; i++)
						{
							selectChannelToolStripMenuItem->Items->Add("Kana³ " + i);
						}
						selectChannelToolStripMenuItem->Text = "Kana³ 1";

						b_PartsDivision = false;

					}else Status->Items["Label"]->Text = "Nie mo¿na otworzyæ pliku.";
	
				 }else Status->Items["Label"]->Text = "Plik " + OpenFileDialog->FileName + " nie istnieje.";
			 }
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Exit();
		 }
private: System::Void fileInfoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 	//File info
			int int_hours, int_minutes, int_seconds;
			if(selectChannelToolStripMenuItem->SelectedIndex != -1){
				MainTextBox->Text = MainTextBox->Text + "Parametry pliku: " + OpenFileDialog->FileName + "\n";
				MainTextBox->Text = MainTextBox->Text + "Rozmiar pliku: " + fileinfo.file_size.ToString() + " bajtów\n";
				MainTextBox->Text = MainTextBox->Text + "Format audio: PCM\n";
				MainTextBox->Text =  MainTextBox->Text + "Liczba kana³ów: " + fileinfo.number_of_channels.ToString() + "\n";
				MainTextBox->Text = MainTextBox->Text + "Czêstotliwoœæ próbkowania: " + fileinfo.sample_rate.ToString() + " próbek/s\n";
				MainTextBox->Text = MainTextBox->Text + "Liczba bitów na próbkê: " + fileinfo.bits_per_sample.ToString() + "\n";
				MainTextBox->Text = MainTextBox->Text + "Liczba próbek w jednym kanale: " + fileinfo.channel_size.ToString() + "\n";
				int_hours = fileinfo.channel_size / fileinfo.sample_rate / 3600;
				int_minutes = fileinfo.channel_size / fileinfo.sample_rate / 60 - int_hours * 60;
				int_seconds = fileinfo.channel_size / fileinfo.sample_rate - int_minutes * 60 - int_hours * 3600; 
				MainTextBox->Text = MainTextBox->Text + "Czas: " + int_hours.ToString() + "g:" + int_minutes.ToString() + "m:" + int_seconds.ToString() + "s\n\n";
			}
		 }
private: System::Void toolStripStatusLabel1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void chiSqareDistributionTestToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 			if(file_opened == true){
				double n, teor, empir;
				int channel;
				
				if(selectChannelToolStripMenuItem->SelectedIndex != -1){
					ObservedDistribution.ZmienRozmiar(10);
					MainTester.GenerujRozkladBenforda(TeoreticDistribution, 9);
					channel = selectChannelToolStripMenuItem->SelectedIndex;
					SelectedData = &ObservedData[channel];
					if(b_PartsDivision == true)SelectedData = &ConvertedData;
					
					if(MainTester.WezRozklad1Cyfr(1, *SelectedData, ObservedDistribution)){
						for(int i = 0; i <= 9; i++)
						{
							ObservedDistribution.WezAtom(ObservedDistribution.ZwrocAtom(i)/divider, i);
						}
						n = ObservedDistribution.ZwrocAtom(9);
						MainTester.TestujZgodnoscChi2(ObservedDistribution, TeoreticDistribution, 9, TestResult);
						MainTextBox->Text =  MainTextBox->Text + "Test zgodnoœci chi2 z rozk³adem Benforda dla kana³u nr " + (selectChannelToolStripMenuItem->SelectedIndex + 1) + " w pliku: " + OpenFileDialog->FileName +"\n";
						MainTextBox->Text =  MainTextBox->Text + "Rozk³ad\n";
						MainTextBox->Text =  MainTextBox->Text + "Cyfra\tOczekiwnay\tZaobserwowany\tRó¿nica\n";
						for(int i=0; i<9;i++)
						{
							teor = Math::Round(TeoreticDistribution[i], 9);
							empir = Math::Round(ObservedDistribution.ZwrocAtom(i)/n*1.0, 9);
							MainTextBox->Text =  MainTextBox->Text + (i+1) + "\t" + teor.ToString() + "\t" + empir.ToString() + "\t" + (Math::Round(empir-teor, 9)).ToString() + "\n";
						}
						MainTextBox->Text = MainTextBox->Text + "Liczba obserwacji\t" + n.ToString() + "\n";
						MainTextBox->Text = MainTextBox->Text + "Wynik testu chi2\t" + Math::Round(TestResult, 3).ToString() + "\n\n";
					}		 
				}
			}
		 }
private: System::Void chiSquareDigitsTestToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 			if(file_opened == true){
				long double srednia, odchstd, variance, n, plevel;

				if(selectChannelToolStripMenuItem->SelectedIndex != -1){
					int channel = selectChannelToolStripMenuItem->SelectedIndex;
					SelectedData = &ObservedData[channel];
					if(b_PartsDivision == true)SelectedData = &ConvertedData;
					ObservedDistribution.ZmienRozmiar(10);
			
					MainTester.GenerujRozkladBenforda(TeoreticDistribution, 9);
					
					if(MainTester.WezRozklad1Cyfr(1, *SelectedData, ObservedDistribution)){
						for(int i = 0; i <= 9; i++)
						{
							ObservedDistribution.WezAtom(ObservedDistribution.ZwrocAtom(i)/divider, i);
						}
						n=ObservedDistribution.ZwrocAtom(9);
						MainTester.Srednia(*SelectedData, srednia);
						MainTester.Wariancja(*SelectedData, srednia, variance);
						odchstd = sqrt(variance);
						MainTextBox->Text =  MainTextBox->Text + "Test zgodnoœci chi2 poszczególnych cyfr z rozk³adem Benforda dla kana³u numer " + (selectChannelToolStripMenuItem->SelectedIndex + 1) + " w pliku: " + OpenFileDialog->FileName +"\n";
						MainTextBox->Text =  MainTextBox->Text + "Rozk³ad\n";
						MainTextBox->Text =  MainTextBox->Text + "Cyfra\tOczekiwany\tZaobserwowany\tZ\tpoziom p\n";
						for(int i=0; i<9;i++)
						{
							MainTextBox->Text =  MainTextBox->Text + (i+1) + "\t" + (Math::Round(TeoreticDistribution[i], 9)).ToString() + "\t" + (Math::Round((ObservedDistribution.ZwrocAtom(i)/n), 9)).ToString();
							MainTester.TestujZgodnoscCyfryChi2(ObservedDistribution, TeoreticDistribution, 9, i + 1, TestResult);
							MainTester.GestoscRozkladuNormalnego(TestResult, srednia, odchstd, plevel);
							MainTextBox->Text = MainTextBox->Text + "\t" + (Math::Round(TestResult, 3)).ToString();
							MainTextBox->Text = MainTextBox->Text + "\t" + (Math::Round(plevel, 9)).ToString() + "\n";
						}
						MainTextBox->Text = MainTextBox->Text + "Liczba obserwacji\t" + n.ToString() + "\n\n";
					}		 	 
				}
			}
		 }
private: System::Void distributionParametersToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 //Distribution parameters
			 long double srednia, odchstd, variance, n;
			 int channel;
			 if(file_opened == true){
				 if(selectChannelToolStripMenuItem->SelectedIndex != -1){
					channel = selectChannelToolStripMenuItem->SelectedIndex;
					SelectedData = &ObservedData[channel];
					if(b_PartsDivision == true)SelectedData = &ConvertedData;
					MainTester.WezRozklad1Cyfr(1, *SelectedData, ObservedDistribution);
					for(int i = 0; i <= 9; i++)
					{
						ObservedDistribution.WezAtom(ObservedDistribution.ZwrocAtom(i)/divider, i);
					}
					n = ObservedDistribution.ZwrocAtom(9);
					MainTester.Srednia(*SelectedData, srednia);
					
					MainTextBox->Text = MainTextBox->Text + "Parametry rozk³adu dla kana³u numer "  + (selectChannelToolStripMenuItem->SelectedIndex + 1) + " w pliku: " + OpenFileDialog->FileName +"\n";
					MainTextBox->Text = MainTextBox->Text + "Liczba obserwacji\t" + n.ToString() + "\n";
					MainTextBox->Text = MainTextBox->Text + "Œrednia:\t" + srednia.ToString() + "\n";
					MainTester.Wariancja(*SelectedData, srednia, variance);
					MainTextBox->Text = MainTextBox->Text + "Wariancja:\t" + variance.ToString() + "\n";
					odchstd = sqrt(variance);
					MainTextBox->Text = MainTextBox->Text + "Odchylenie standardowe:\t" + odchstd.ToString() + "\n\n";
				 }
			 }
		 }
private: System::Void meter1ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 			 if(file_opened == true){
				double n, teor, empir;
				int channel;
				
				if(selectChannelToolStripMenuItem->SelectedIndex != -1){
					ObservedDistribution.ZmienRozmiar(10);
					MainTester.GenerujRozkladBenforda(TeoreticDistribution, 9);
					channel = selectChannelToolStripMenuItem->SelectedIndex;
					SelectedData = &ObservedData[channel];
					if(b_PartsDivision == true)SelectedData = &ConvertedData;
					
					if(MainTester.WezRozklad1Cyfr(1, *SelectedData, ObservedDistribution)){
						for(int i = 0; i <= 9; i++)
						{
							ObservedDistribution.WezAtom(ObservedDistribution.ZwrocAtom(i)/divider, i);
						}
						n = ObservedDistribution.ZwrocAtom(9);
						MainTester.TestujMiernik1(ObservedDistribution, TeoreticDistribution, TestResult);
						MainTextBox->Text =  MainTextBox->Text + "Miernik 1 dla rozk³adu Benforda dla kana³u numer " + (selectChannelToolStripMenuItem->SelectedIndex + 1) + " w pliku: " + OpenFileDialog->FileName +"\n";
						MainTextBox->Text =  MainTextBox->Text + "Rozk³ad\n";
						MainTextBox->Text =  MainTextBox->Text + "Cyfra\tOczekiwany\tZaobserwowany\tRó¿nica\n";
						for(int i=0; i<9;i++)
						{
							teor = Math::Round(TeoreticDistribution[i], 9);
							empir = Math::Round(ObservedDistribution.ZwrocAtom(i)/n*1.0, 9);
							MainTextBox->Text =  MainTextBox->Text + (i+1) + "\t" + teor.ToString() + "\t" + empir.ToString() + "\t" + (Math::Round(empir-teor, 9)).ToString() + "\n";
						}
						MainTextBox->Text = MainTextBox->Text + "Liczba obserwacji\t" + n.ToString() + "\n";
						MainTextBox->Text = MainTextBox->Text + "Wartoœæ Miernika 1\t" + Math::Round(TestResult, 5).ToString() + "\n\n";
					}		 
				}
			}
		 }
private: System::Void clearAllDivisionsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
 			 b_PartsDivision = false;
			 divider = 1;
		 }
private: System::Void minimizeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(selectChannelToolStripMenuItem->SelectedIndex != -1){
				channel = selectChannelToolStripMenuItem->SelectedIndex;
				SelectedData = &ObservedData[channel];
				if(b_PartsDivision == true)SelectedData = &ConvertedData;
				MainTextBox->Text = MainTextBox->Text + "Rozk³ad z kana³u nr " + (selectChannelToolStripMenuItem->SelectedIndex + 1) + " zosta³ zastosowany do liczebnoœci oko³o " + Minimize->Text + ".\n";
				MainTester.WezRozklad1Cyfr(1, *SelectedData, ObservedDistribution);
				n = ObservedDistribution.ZwrocAtom(9);
				divider=n/(Convert::ToInt32(Minimize->Text));
			 }
		 }
private: System::Void divideToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
			 			int channel;
			if(selectChannelToolStripMenuItem->SelectedIndex != -1){
				channel = selectChannelToolStripMenuItem->SelectedIndex;
				long n = ObservedData[channel].WezRozmiar();
				MainTextBox->Text = MainTextBox->Text + "Kana³ nr " + (selectChannelToolStripMenuItem->SelectedIndex + 1) + " zosta³ podzielony wed³ug czêstotliwoœci " + Divide1->Text + " Hz.\n";
				long interval = (fileinfo.sample_rate/(Convert::ToInt32(Divide1->Text)));
				Converti.SredniaInterwalowa(ObservedData[channel], ConvertedData, interval);
				b_PartsDivision = true;
			}
		 }
private: System::Void divideToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
 			int channel;
			if(selectChannelToolStripMenuItem->SelectedIndex != -1){
				channel = selectChannelToolStripMenuItem->SelectedIndex;
				long n = ObservedData[channel].WezRozmiar();
				MainTextBox->Text = MainTextBox->Text + "Kana³ nr "  + (selectChannelToolStripMenuItem->SelectedIndex + 1) + " zosta³ podzielony na oko³o " + Divide->Text + " czêœci.\n";
				long interval = n/(Convert::ToInt32(Divide->Text));
				Converti.SredniaInterwalowa(ObservedData[channel], ConvertedData, interval);
				b_PartsDivision = true;
			}
		 }
private: System::Void createdByKonradWroñskiToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void divideByFreqnecyHzToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}


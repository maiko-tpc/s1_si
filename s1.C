{
  const double s1_r1 = 48/2.0;
  const double s1_r2 = 96/2.0;  
  
  // Rear histogram
  
  TH2Poly *h_rear = new TH2Poly();
  h_rear->SetTitle("S1 Rear Hit Pattern");

  Double_t s1r_x[20], s1r_y[20];
  
  Int_t s1r_i;
  double dtheta1r = 2*TMath::Pi()/16.0;
  double dtheta2r = dtheta1r/9.0;

  double theta_start, theta_end;
  int i;
  double tmp_theta;
  
  for(s1r_i=0; s1r_i<16; s1r_i++){
    theta_start = s1r_i*dtheta1r;
    theta_end = (s1r_i+1)*dtheta1r;    

    i=0;
    s1r_x[i] = s1_r1*cos(theta_start);
    s1r_y[i] = s1_r1*sin(theta_start);    

    // outer circle
    tmp_theta = theta_start;
    for(i=1; i<=10; i++){
      s1r_x[i] = s1_r2*cos(tmp_theta);
      s1r_y[i] = s1_r2*sin(tmp_theta);      
      tmp_theta += dtheta2r;
    }

    // inner circle
    tmp_theta = theta_end;
    for(i=11; i<20; i++){
      s1r_x[i] = s1_r1*cos(tmp_theta);
      s1r_y[i] = s1_r1*sin(tmp_theta);      
      tmp_theta -= dtheta2r;
    }
    
    h_rear->AddBin(20, s1r_x, s1r_y);
  }
  
  //  h_rear->Draw("colz");
  
  
  // Front histogram
  TH2Poly *h_front = new TH2Poly();
  h_front->SetTitle("S1 Front Hit Pattern");
  
  Double_t s1f_x[80], s1f_y[80];
  int s1f_i, s1f_j;
  
  double dtheta1f = 2*TMath::Pi()/4.0;
  double dtheta2f = dtheta1f/39.0;
  
  double r_start, r_end;
  double dr = (s1_r2 - s1_r1)/16.0;
  
  for(s1f_i=0; s1f_i<4; s1f_i++){
    theta_start = s1f_i*dtheta1f;
    theta_end = (s1f_i+1)*dtheta1f;    

    for(s1f_j=0; s1f_j<16; s1f_j++){
      r_start = s1_r1 + s1f_j*dr;
      r_end = s1_r1 + (s1f_j+1)*dr;      
      
      i=0;
      s1f_x[i] = r_start*cos(theta_start);
      s1f_y[i] = r_start*sin(theta_start);    
      
      tmp_theta = theta_start;
      for(i=1; i<=40; i++){
	s1f_x[i] = r_end*cos(tmp_theta);
	s1f_y[i] = r_end*sin(tmp_theta);    	
	tmp_theta += dtheta2f;
      }
      
      // inner circle
      tmp_theta = theta_end;
      for(i=41; i<80; i++){
	s1f_x[i] = r_start*cos(tmp_theta);
	s1f_y[i] = r_start*sin(tmp_theta);      
	tmp_theta -= dtheta2f;
      }
      
      h_front->AddBin(80, s1f_x, s1f_y);
      
    }
  }


  // matrix histogram
  TH2Poly *h_matrix = new TH2Poly();
  h_matrix->SetTitle("S1 Matrix Hit Pattern");

  Double_t s1m_x[20], s1m_y[20];
  Int_t s1m_i, s1m_j;

  double dtheta1m = 2*TMath::Pi()/16.0;
  double dtheta2m = dtheta1r/9.0;

  for(s1m_i=0; s1m_i<16; s1m_i++){
    theta_start = s1m_i*dtheta1m;
    theta_end = (s1m_i+1)*dtheta1m;    

    for(s1m_j=0; s1m_j<16; s1m_j++){
      r_start = s1_r1 + s1m_j*dr;
      r_end = s1_r1 + (s1m_j+1)*dr;      

      i=0;
      s1m_x[i] = r_start*cos(theta_start);
      s1m_y[i] = r_start*sin(theta_start);    
      
      tmp_theta = theta_start;
      for(i=1; i<=10; i++){
	s1m_x[i] = r_end*cos(tmp_theta);
	s1m_y[i] = r_end*sin(tmp_theta);      
	tmp_theta += dtheta2m;
      }

      // inner circle
      tmp_theta = theta_end;
      for(i=11; i<20; i++){
	s1m_x[i] = r_start*cos(tmp_theta);
	s1m_y[i] = r_start*sin(tmp_theta);      
	tmp_theta -= dtheta2m;
      }
      
      h_matrix->AddBin(20, s1m_x, s1m_y);
    }
  }
  
  h_front->Fill(20,30);
  h_front->Fill(20,30);
  h_front->Fill(-10,25);  
  
  h_rear->Fill(20,30);
  h_rear->Fill(20,30);
  h_rear->Fill(-10,25);  

  h_matrix->Fill(20,30);
  h_matrix->Fill(20,30);
  h_matrix->Fill(-10,25);  
  
  TCanvas *c1 = new TCanvas("c1", "front", 600,600);  
  c1->cd();
  h_front->Draw("colz");
  h_front->Draw("same");  
  
  TCanvas *c2 = new TCanvas("c2", "rear", 600,600);  
  c2->cd();
  h_rear->Draw("colz");
  h_rear->Draw("same");  

  TCanvas *c3 = new TCanvas("c3", "matrix", 600,600);  
  c3->cd();
  h_matrix->Draw("colz");
  h_matrix->Draw("same");  
}

# BmpEdgeExtractor
Simple Edge extractor for Microsoft Bitmap files.
Supports most BMP files out there, except OS/2, Windows 2.0 Bitmaps or earlier ones.

Usage: 

    bmpedge <filein> <fileout> : 
   Detects edges in ```filein```, and saves them into ```fileout```.
    
    bmpedge --info | -i  <file>  : 
   Shows bitmap info about the input file.
    
    
## Examples:
<i><em>On B&W images:</i></em>

  input
  <img width="120" alt="ex1From" src="https://user-images.githubusercontent.com/24901834/147371070-8a6bb3b2-ecd4-4709-8661-65860a86296b.png">
  gives<img width="120" alt="ex1To" src="https://user-images.githubusercontent.com/24901834/147371071-ea7ff7e4-5c0a-490f-8c0b-5c5192ce9c57.png">
  
<br />

<i><em>On color, higher-resolution images:</em></i>

  input
  <img width="250" alt="ex2From (2)" src="https://user-images.githubusercontent.com/24901834/147371376-976e7e10-0412-41e9-9fa6-8f0d10a57f54.png">
  gives
  <img width="250" alt="ex2To (2)" src="https://user-images.githubusercontent.com/24901834/147371374-2064c2c7-3631-4555-b51c-ea96a37c30d6.png">

<i><em>On complex images:</em></i>

  input
  ![rer](https://user-images.githubusercontent.com/24901834/147371516-579788d5-0f50-45b2-87a3-e047771fcf59.png)
  gives
  ![rer2](https://user-images.githubusercontent.com/24901834/147371518-c8893621-0b33-431e-b5f8-0730e3b13604.png)


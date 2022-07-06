xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 114;
 27.00000;7.49900;27.00000;,
 27.00000;7.50000;30.00000;,
 27.00000;5.50000;30.00000;,
 27.00000;5.50000;27.00000;,
 27.00000;7.50000;30.00000;,
 -27.00000;7.50000;30.00000;,
 -27.00000;5.50000;30.00000;,
 27.00000;5.50000;30.00000;,
 -27.00000;7.50000;30.00000;,
 -27.00000;7.49900;27.00000;,
 -27.00000;5.50000;27.00000;,
 -27.00000;5.50000;30.00000;,
 27.00000;7.49900;27.00000;,
 -27.00000;7.49900;27.00000;,
 -27.00000;5.50000;27.00000;,
 27.00000;5.50000;27.00000;,
 -27.00000;7.50000;-30.00000;,
 27.00000;7.50000;-30.00000;,
 27.00000;5.50000;-30.00000;,
 -27.00000;5.50000;-30.00000;,
 -27.00000;7.49900;-27.00000;,
 -27.00000;7.50000;-30.00000;,
 -27.00000;5.50000;-30.00000;,
 -27.00000;5.50000;-27.00000;,
 27.00000;7.49900;-27.00000;,
 27.00000;7.50000;-30.00000;,
 -27.00000;7.50000;-30.00000;,
 27.00000;7.49900;-27.00000;,
 30.00000;7.50000;-27.00000;,
 30.00000;5.50000;-27.00000;,
 27.00000;5.50000;-27.00000;,
 30.00000;7.50000;-27.00000;,
 30.00000;7.50000;27.00000;,
 30.00000;5.50000;27.00000;,
 30.00000;5.50000;-27.00000;,
 30.00000;7.50000;27.00000;,
 27.00000;7.49900;27.00000;,
 27.00000;5.50000;27.00000;,
 30.00000;5.50000;27.00000;,
 27.00000;7.49900;-27.00000;,
 27.00000;7.49900;27.00000;,
 27.00000;5.50000;27.00000;,
 27.00000;5.50000;-27.00000;,
 -30.00000;7.50000;27.00000;,
 -30.00000;7.50000;-27.00000;,
 -30.00000;5.50000;-27.00000;,
 -30.00000;5.50000;27.00000;,
 -30.00000;7.50000;-27.00000;,
 -27.00000;7.49900;-27.00000;,
 -27.00000;5.50000;-27.00000;,
 -30.00000;5.50000;-27.00000;,
 -27.00000;7.49900;27.00000;,
 -30.00000;7.50000;27.00000;,
 -30.00000;5.50000;27.00000;,
 -27.00000;5.50000;27.00000;,
 -30.00000;7.50000;-27.00000;,
 -30.00000;7.50000;27.00000;,
 -30.00000;5.50000;27.00000;,
 -30.00000;5.50000;-27.00000;,
 27.00000;7.50000;-30.00000;,
 30.00000;7.50000;-30.00000;,
 30.00000;5.50000;-30.00000;,
 27.00000;5.50000;-30.00000;,
 30.00000;7.50000;-30.00000;,
 30.00000;5.50000;-30.00000;,
 30.00000;7.50000;-30.00000;,
 27.00000;7.50000;-30.00000;,
 27.00000;5.50000;-30.00000;,
 30.00000;5.50000;-30.00000;,
 -30.00000;7.50000;-30.00000;,
 -30.00000;5.50000;-30.00000;,
 -30.00000;7.50000;-30.00000;,
 -30.00000;5.50000;-30.00000;,
 -27.00000;7.50000;-30.00000;,
 -30.00000;7.50000;-30.00000;,
 -30.00000;5.50000;-30.00000;,
 -27.00000;5.50000;-30.00000;,
 -30.00000;7.50000;30.00000;,
 -30.00000;5.50000;30.00000;,
 -30.00000;7.50000;30.00000;,
 -30.00000;5.50000;30.00000;,
 -27.00000;7.49900;27.00000;,
 -27.00000;5.50000;27.00000;,
 30.00000;7.50000;30.00000;,
 30.00000;5.50000;30.00000;,
 30.00000;7.50000;30.00000;,
 30.00000;5.50000;30.00000;,
 30.00000;7.50000;27.00000;,
 30.00000;5.50000;27.00000;,
 30.00000;-2.50000;-30.00000;,
 -30.00000;-2.50000;-30.00000;,
 30.00000;5.50000;-30.00000;,
 30.00000;5.50000;30.00000;,
 30.00000;-2.50000;30.00000;,
 30.00000;-2.50000;-30.00000;,
 30.00000;5.50000;30.00000;,
 -30.00000;5.50000;30.00000;,
 -30.00000;-2.50000;30.00000;,
 30.00000;-2.50000;30.00000;,
 -30.00000;5.50000;30.00000;,
 -30.00000;5.50000;-30.00000;,
 -30.00000;-2.50000;-30.00000;,
 -30.00000;-2.50000;30.00000;,
 -30.00000;-2.50000;-30.00000;,
 30.00000;-2.50000;-30.00000;,
 -27.00000;7.49900;-27.00000;,
 -2.25000;7.65000;18.75000;,
 2.25000;7.65000;18.75000;,
 2.25000;7.65000;-18.75000;,
 -2.25000;7.65000;-18.75000;,
 18.75000;7.65000;2.25000;,
 18.75000;7.65000;-2.25000;,
 -18.75000;7.65000;-2.25000;,
 -18.75000;7.65000;2.25000;;
 
 44;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;8,1,12,13;,
 4;14,15,2,11;,
 4;16,17,18,19;,
 4;20,21,22,23;,
 4;20,24,25,26;,
 4;27,28,29,30;,
 4;31,32,33,34;,
 4;35,36,37,38;,
 4;35,28,39,40;,
 4;41,42,29,38;,
 4;43,44,45,46;,
 4;47,48,49,50;,
 4;51,52,53,54;,
 4;51,48,55,56;,
 4;57,58,49,54;,
 4;59,60,61,62;,
 4;63,28,29,64;,
 4;27,28,65,66;,
 4;67,68,29,30;,
 4;69,21,22,70;,
 4;47,71,72,50;,
 4;47,48,73,74;,
 4;75,76,49,50;,
 4;8,77,78,11;,
 4;79,52,53,80;,
 4;79,5,81,56;,
 4;57,82,6,80;,
 4;35,83,84,38;,
 4;85,1,2,86;,
 4;4,83,87,40;,
 4;41,88,84,7;,
 4;67,42,49,76;,
 4;75,68,89,90;,
 4;91,92,93,94;,
 4;95,96,97,98;,
 4;99,100,101,102;,
 4;99,92,61,70;,
 4;103,104,93,102;,
 4;51,36,39,105;,
 4;106,107,108,109;,
 4;110,111,112,113;;
 
 MeshMaterialList {
  5;
  44;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  4,
  4,
  4,
  4,
  4,
  4,
  2,
  1,
  1;;
  Material {
   0.800000;0.329600;0.003200;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.500000;0.206000;0.002000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.511200;0.800000;0.395200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Wood035_1K_Color.png";
   }
  }
 }
 MeshNormals {
  23;
  -1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;-1.000000;,
  -0.000125;1.000000;0.000125;,
  0.000083;1.000000;-0.000250;,
  -0.000083;1.000000;-0.000250;,
  -0.000125;1.000000;-0.000125;,
  0.000125;1.000000;-0.000125;,
  0.000000;-1.000000;-0.000000;,
  0.000125;1.000000;0.000125;,
  -0.000083;1.000000;0.000250;,
  0.000083;1.000000;0.000250;,
  -0.000250;1.000000;-0.000083;,
  -0.000250;1.000000;0.000083;,
  0.000250;1.000000;0.000083;,
  0.000250;1.000000;-0.000083;,
  -0.000167;1.000000;0.000167;,
  0.000167;1.000000;0.000167;,
  0.000167;1.000000;-0.000167;,
  -0.000167;1.000000;-0.000167;,
  0.000000;1.000000;0.000000;,
  0.000000;1.000000;0.000000;;
  44;
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;0,0,0,0;,
  4;5,6,7,8;,
  4;9,9,9,9;,
  4;3,3,3,3;,
  4;0,0,0,0;,
  4;10,4,11,12;,
  4;3,3,3,3;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;13,14,4,7;,
  4;9,9,9,9;,
  4;0,0,0,0;,
  4;3,3,3,3;,
  4;2,2,2,2;,
  4;8,10,15,16;,
  4;9,9,9,9;,
  4;3,3,3,3;,
  4;1,1,1,1;,
  4;4,14,17,11;,
  4;9,9,9,9;,
  4;3,3,3,3;,
  4;0,0,0,0;,
  4;15,10,12,18;,
  4;9,9,9,9;,
  4;2,2,2,2;,
  4;0,0,0,0;,
  4;19,5,8,16;,
  4;9,9,9,9;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;6,20,13,7;,
  4;9,9,9,9;,
  4;9,9,9,9;,
  4;3,3,3,3;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;0,0,0,0;,
  4;21,21,21,21;,
  4;9,9,9,9;,
  4;8,7,4,10;,
  4;22,22,22,22;,
  4;22,22,22,22;;
 }
 MeshTextureCoords {
  114;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;;
 }
}

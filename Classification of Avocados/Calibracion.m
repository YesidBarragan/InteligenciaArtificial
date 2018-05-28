
%bag = rosbag('cosa_.txt');
%bagselect1 = select(bag, 'Topic', '/kinect2/sd/points ')
%msgs = readMessages(bagselect1, [1:14])

%pcloud = msgs{1,1};
 XYZ=load('Aguacate1.txt');
%XYZ = readXYZ(pcloud) ;
X=XYZ(:,1);
Y=XYZ(:,2);
Z=XYZ(:,3);
% rgb = readRGB(pcloud);l
% R=rgb(:,1);
% G=rgb(:,2);
 % B=rgb(:,3);
 R=XYZ(:,4);
 G=XYZ(:,5);
 B=XYZ(:,6);
% d=;
d=X*0;
d=d*255;

% L=length(X);
% for k=1:L
%     P=rotx(-90)*[X(k);Y(k);Z(k)];
%     X(k) = P(1);
%     Y(k) = P(2);
%     Z(k) = P(3);
% end
% figure(1)
%     plot3(X,Y,Z,255)
%     grid on
%     grid on
%     xlabel('x')
%     ylabel('y')
%     zlabel('z')

c=[R,G,B]/255;

scatter3(X,Y,Z,1,c);
axis([-0.2 0.2 0 2 -0.3 0.3])
xlabel('X');
ylabel('Y');
zlabel('Z');


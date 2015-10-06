#ifndef						AINSTRUCTION_MODEL_HPP_
# define					AINSTRUCTION_MODEL_HPP_

# define					CONTENT_BYTE_SIZE 10
# define					INDEX_BYTE_INSTRUCTIONCODE 0
# define					INDEX_BYTE_RETURNTYPE 4
# define					INDEX_BYTE_ISSYNCHRONE 8


# include					<QByteArray>

class						AInstructionModel
{
public:
  AInstructionModel();
  AInstructionModel(QByteArray *byteArray);
  ~AInstructionModel();
  void						setInstructionCode(int instructionCode);
  int						getInstructionCode() const;
  void						setReturnType(int returnType);
  int						getReturnType() const;
  void						setIsSynchrone(bool isSynchrone);
  bool						getIsSynchrone() const;
  void						setByteArray(QByteArray *byteArray);
  QByteArray					*getByteArray() const;
private:
  void						_init();
private:
  int						*_instructionCode;
  int						*_returnType;
  bool						*_isSynchrone;
  QByteArray					*_byteArray;
};

#endif		/* !AINSTRUCTION_MODEL_HPP_ */
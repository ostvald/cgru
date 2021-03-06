#pragma once

#include "../libafanasy/name_af.h"
#include "../libafanasy/blockdata.h"
#include "../libafanasy/taskprogress.h"

#include "item.h"

#include <QtGui/QImage>

class ListTasks;

class ItemJobTask : public Item
{
public:
	ItemJobTask( ListTasks * i_list, const af::BlockData *pBlock, int numtask);
	~ItemJobTask();

	virtual bool calcHeight();

	void upProgress( const af::TaskProgress & tp);

	inline bool isBlockNumeric() const { return m_block->isNumeric();}

	inline int getBlockNum() const { return m_blocknum; }
	inline int getTaskNum()  const { return m_tasknum;  }

	const std::string & getWDir() const;
	const std::vector<std::string> genFiles() const;
	int getFramesNum() const;

	af::TaskProgress taskprogress;

	virtual const QVariant getToolTip() const;
	virtual const QString getSelectString() const;

	void showThumbnail();

	static const int ItemId = 2;
	static const int WidthInfo;

	bool compare( int type, const ItemJobTask & other, bool ascending) const;

	void taskFilesReceived( const af::MCTaskUp & i_taskup );

protected:
	virtual void paint( QPainter *painter, const QStyleOptionViewItem &option) const;

private:
	void thumbsCLear();

private:
	static const int TaskHeight = 13;
	static const int TaskThumbHeight = 100;

private:
	ListTasks * m_list;

	int m_blocknum;
	int m_tasknum;
	const af::BlockData * m_block;

	int m_thumbs_num;
	QImage ** m_thumbs_imgs;
};
